// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DDObject/DDUserWidget.h"
#include "DDFrameWidget.generated.h"


class UOverlay;
class UCanvasPanel;
class UDDPanelWidget;
class UImage;
/**
 *
 */
UCLASS()
class DATADRIVEN_API UDDFrameWidget : public UDDUserWidget
{
	GENERATED_BODY()

public:

	virtual bool Initialize() override;

	//��ʾUI
	UFUNCTION()
		void ShowUIPanel(FName PanelName);

	//����UI
	UFUNCTION()
		void HideUIPanel(FName PanelName);

	//����UI
	UFUNCTION()
		void ExitUIPanel(FName PanelName);

	//����PanelWidget���ٺ��WorkLayout
	UFUNCTION()
		void ExitCallBack(ELayoutType LayoutType, UPanelWidget* InLayout);

	//��ȡ���ص�PanelWidget
	UFUNCTION()
		void AcceptPanelWidget(FName BackName, UUserWidget* BackWidget);

	//��ȡ��ǰ���ص�PanelWidget, ����ʾֻ���ص�ջ
	UFUNCTION()
		void AcceptAdvancePanel(FName BackName, UUserWidget* BackWidget);

public:



protected:

	//��ǰ����Panel���ڴ�
	void AdvanceLoadPanel(FName PanelName);

	//ִ�н���UI
	void DoEnterUIPanel(FName PanelName);

	//ִ����ʾUI
	void DoShowUIPanel(FName PanelName);

	//����UI, ��һ��
	void EnterPanelDoNothing(UCanvasPanel* WorkLayout, UDDPanelWidget* PanelWidget);
	void EnterPanelDoNothing(UOverlay* WorkLayout, UDDPanelWidget* PanelWidget);

	void EnterPanelHideOther(UCanvasPanel* WorkLayout, UDDPanelWidget* PanelWidget);
	void EnterPanelHideOther(UOverlay* WorkLayout, UDDPanelWidget* PanelWidget);

	void EnterPanelReverse(UCanvasPanel* WorkLayout, UDDPanelWidget* PanelWidget);
	void EnterPanelReverse(UOverlay* WorkLayout, UDDPanelWidget* PanelWidget);

	//��ʾUI, UI�Ѿ��ڿ���
	void ShowPanelDoNothing(UDDPanelWidget* PanelWidget);
	void ShowPanelHideOther(UDDPanelWidget* PanelWidget);
	void ShowPanelReverse(UDDPanelWidget* PanelWidget);

	//����UI
	void HidePanelDoNothing(UDDPanelWidget* PanelWidget);
	void HidePanelHideOther(UDDPanelWidget* PanelWidget);
	void HidePanelReverse(UDDPanelWidget* PanelWidget);

	//����UI
	void ExitPanelDoNothing(UDDPanelWidget* PanelWidget);
	void ExitPanelHideOther(UDDPanelWidget* PanelWidget);
	void ExitPanelReverse(UDDPanelWidget* PanelWidget);

	//�������ֵ�WorkLayout
	void ActiveMask(UCanvasPanel* WorkLayout, EPanelLucenyType LucenyType);
	void ActiveMask(UOverlay* WorkLayout, EPanelLucenyType LucenyType);
	//ת�����ֵ�����λ��, ���ǰ�MaskPanel������һ��Panel����һ��
	void TransferMask(UDDPanelWidget* PanelWidget);

	//��MaskPanel�Ƴ�, �����Layout�����Ϊ��, ˵��MaskPanel׼����ӵ����Layout
	void RemoveMaskPanel(UPanelWidget* WorkLayout = NULL);

protected:

	//���ڵ�
	UCanvasPanel* RootCanvas;

	TArray<UOverlay*> ActiveOverlay;

	TArray<UOverlay*> UnActiveOverlay;

	TArray<UCanvasPanel*> ActiveCanvas;

	TArray<UCanvasPanel*> UnActiveCanvas;

	//����UIPanel��, �����ǿ��PanelName�����ObjectNameһ��
	TMap<FName, UDDPanelWidget*> AllPanelGroup;

	//UIPanel��ʾ��, �����ǿ��PanelName�����ObjectNameһ��
	TMap<FName, UDDPanelWidget*> ShowPanelGroup;

	//ջ�ṹ����
	TMap<FName, UDDPanelWidget*> PopPanelStack;

	//�ѽ�������ؽ��̵Ķ���
	TArray<FName> LoadedPanelName;

	//����ͼƬ
	UPROPERTY()
		UImage* MaskPanel;

	//͸����ֵ
	FLinearColor NormalLucency;
	FLinearColor TranslucenceLucency;
	FLinearColor ImPenetrableLucency;
};
