// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DDObject/DDUserWidget.h"
#include "DDPanelWidget.generated.h"


/**
 *
 */
UCLASS()
class DATADRIVEN_API UDDPanelWidget : public UDDUserWidget
{
	GENERATED_BODY()

public:

	virtual bool Initialize() override;

	//Panel��������
	virtual void PanelEnter();  //��һ�ν������
	virtual void PanelDisplay();//��ʾ����
	virtual void PanelFreeze(); //��ջ�б�����
	virtual void PanelResume(); //�ⶳ
	virtual void PanelHidden(); //����, ����ջ��
	virtual void PanelExit(); //����, �Ƴ�����

	//�����ص�����
	UFUNCTION(BlueprintImplementableEvent)
	float DisplayEnterMovie();
	UFUNCTION(BlueprintImplementableEvent)
	float DisplayLeaveMove();

public:

	UPROPERTY(EditAnywhere)
		FUINature UINature;

protected:

	void ShowSelfPanel();

	void HideSelfPanel();

	void ExitSelfPanel();

	void ShowUIPanel(FName PanelName);

	void HideUIPanel(FName PanelName);

	void ExitUIPanel(FName PanelName);

	//�Ƴ�UI, ִ�лص�
	void RemoveCallBack();

	//���غ���
	void SetSelfHidden();

protected:

	//���ֵ��UIFrame������ڵ�ģ��ID
	int32 UIFrameModuleIndex;
	//UIFrame������
	static FName UIFrameName;
	//��ʾUI�ķ�����
	static FName ShowUIPanelName;
	//�ر�UI�ķ�����
	static FName HideUIPanelName;
	//����UI�ķ�����
	static FName ExitUIPanelName;
	//���ٻص�������
	static FName ExitCallBackName;

protected:

	DDOBJFUNC_ONE(OperatorUIPanel, FName, PanelName);
	DDOBJFUNC_TWO(ExitCallBack, ELayoutType, LayoutType, UPanelWidget*, WorkLayout);

};


