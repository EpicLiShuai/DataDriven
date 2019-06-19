// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DDMM.h"
#include "DDModel.generated.h"

class UDDModule;
class IDDOO;

/**
 *
 */
UCLASS()
class DATADRIVEN_API UDDModel : public UObject, public IDDMM
{
	GENERATED_BODY()

public:

	virtual void ModelInit() {}

	virtual void ModelBeginPlay() {}

	////ע�Ḹ��ģ��
	//void RegisterSuperModule(UDDModule* SuperMod);
	////ע�ᵥ������ģ��
	//void RegisterChildModule(UDDModule* ChildMod);
	//ע�����
	void RegisterObject(IDDOO* ObjectInst);
	//���ݵ�Tick����
	virtual void ModelTick(float DeltaSeconds);
	//�������ֻ�ȡ����
	void GetSelfObject(TArray<FName> ObjectNameGroup, TArray<IDDOO*>& TargetObjectGroup);
	//�������ֻ�ȡ��������,����ȫ�����������
	int32 GetOtherObject(TArray<FName> ObjectNameGroup, TArray<IDDOO*>& TargetObjectGroup);
	//�������������ȡ��ͬ�����������,���������Ķ��������
	int32 GetClassOtherObject(TArray<FName> ObjectNameGroup, TArray<IDDOO*>& TargetObjectGroup);
	//�������ֻ�ȡ��Ķ���
	void GetSelfClass(TArray<FName> ObjectNameGroup, TArray<IDDOO*>& TargetObjectGroup);
	//�������ֻ�ȡ���������Ķ���
	void GetOtherClass(TArray<FName> ObjectNameGroup, TArray<IDDOO*>& TargetObjectGroup);
	//��ȡ���ж���
	void GetAll(TArray<IDDOO*>& TargetObjectGroup);
	
	//���ٶ���
	void DestroyObject(EAgreementType Agreement, TArray<FName> ObjectNameGroup);
	//�������
	void EnableObject(EAgreementType Agreement, TArray<FName> ObjectNameGroup);
	//ʧ�����
	void DisableObject(EAgreementType Agreement, TArray<FName> ObjectNameGroup);

	//����ȫ�����������
	int32 GetObjectGroupNum() const;
	//����ĳ����Ķ��������
	int32 GetClassObjectGroupNum(FName ObjectClassName) const;

protected:

	//��������ɾ������
	void RemoveObject(FName ObjectName);
	//��������ɾ���༯��
	void RemoveObjectClass(FName ObjectClassName);

protected:

	////����ģ��
	//UDDModule* SuperModule;
	////�Ӽ�ģ��
	//TMap<int32, UDDModule*> ChildModule;
	//ģ�����
	TMap<FName, IDDOO*> ObjectGroup;
	//ģ�������
	TMap<FName, TArray<IDDOO*>> ObjectClassGroup;

	//�ȴ��������ڵĶ���
	TArray<IDDOO*> ObjectLifeGroup;
	//����Tick�����Ķ���
	TArray<IDDOO*> ObjectTickGroup;

	//�����������ڵĶ���
	TArray<IDDOO*> ObjectDestroyGroup;
	//�ͷ����ں���,ִֻ��һ�ξ�ȫ���ͷ�
	TArray<IDDOO*> ObjectReleaseGroup;
	//��ʱ�����������ڵĶ���,ȷ���Ѿ����������
	TArray<IDDOO*> PreObjectDestroyGroup;

};
