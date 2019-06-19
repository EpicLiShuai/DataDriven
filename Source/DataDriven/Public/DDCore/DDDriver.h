// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DDCommon/DDCommon.h"
#include "DDCenterModule.h"
#include "DDDriver.generated.h"

class USceneComponent;
class IDDOO;

UCLASS()
class DATADRIVEN_API ADDDriver : public AActor
{
	GENERATED_BODY()
	
public:

	ADDDriver();

	virtual void PostInitializeComponents() override;

	virtual void Tick(float DeltaTime) override;

	//����ģ�鷽��
	void ExecuteFunction(DDModuleAgreement Agreement, DDParam* Param);
	//���ö��󷽷�
	void ExecuteFunction(DDObjectAgreement Agreement, DDParam* Param);

#if WITH_EDITOR
	//�����޸ķ���
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

	//�ṩ����Դ�ǽ���ע��
	bool RegisterToModule(IDDOO* Object);


	//ע����÷���
	template<typename RetType, typename... VarTypes>
	DDFunHandle RegisterFunPort(int32 ModuleID, FName CallName, TFunction<RetType(VarTypes...)> InsFun);

public:

	UPROPERTY(EditAnywhere, NoClear, BlueprintReadOnly, Category = "DataDriven")
		USceneComponent* RootScene;

	UPROPERTY(EditAnywhere, NoClear, BlueprintReadOnly, Category = "DataDriven")
		UDDCenterModule* Center;

	//ģ���Ӧ��ö������
	UPROPERTY(EditDefaultsOnly, Category = "DataDriven")
		FName ModuleType;

protected:

	virtual void BeginPlay() override;

	//ע��GamePlay��������
	void RegisterGamePlay();


protected:

	//�Ƿ��Ѿ�����BeginPlay����
	bool IsBeginPlay;

	
	
};

template<typename RetType, typename... VarTypes>
DDFunHandle ADDDriver::RegisterFunPort(int32 ModuleID, FName CallName, TFunction<RetType(VarTypes...)> InsFun)
{
	return Center->RegisterFunPort<RetType, VarTypes...>(ModuleID, CallName, InsFun);
}
