// Fill out your copyright notice in the Description page of Project Settings.


#include "DDDriver.h"
#include "DDOO.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ADDDriver::ADDDriver()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootScene = CreateDefaultSubobject<USceneComponent>(TEXT("RootScene"));
	RootComponent = RootScene;

	Center = CreateDefaultSubobject<UDDCenterModule>(TEXT("Center"));
	Center->SetupAttachment(RootComponent);
}

void ADDDriver::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	//ע��Driver��UDDCommon����
	UDDCommon::Get()->InitDriver(this);
	//����Ϸ����֮ǰ�������һ��ģ��	ID���趨, ���������ע����ģ�鵽����
	Center->IterChangeModuleType(Center, ModuleType);
	//ָ����ģ��ID���ռ�ģ�鵽������
	Center->TotalGatherModule(ModuleType);
	//��������ģ���ģ��
	Center->IterCreateManager(Center);
}

// Called when the game starts or when spawned
void ADDDriver::BeginPlay()
{
	Super::BeginPlay();

	//ע��GamePlay�����
	RegisterGamePlay();

	//��������Init����
	Center->IterModuleInit(Center);
}

void ADDDriver::RegisterGamePlay()
{
	//��ȡGameInstance
	UGameInstance* GameInstance = UGameplayStatics::GetGameInstance(GetWorld());
	//������ڲ��Ҽ̳���IDDOO,��ע���Center,�����Ͷ���������GameInstance
	if (GameInstance && Cast<IDDOO>(GameInstance))
		Cast<IDDOO>(GameInstance)->RegisterToModule("Center", "GameInstacne", "GameInstacne");

	//��ȡController����ע�ᵽDDCommon
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	//ע�ᵽCommon
	if (!PlayerController)
		DDH::Debug() << "No PlayerController" << DDH::Endl();
	else
		UDDCommon::Get()->InitController(PlayerController);
}

// Called every frame
void ADDDriver::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!IsBeginPlay)
	{
		//��������Begin����
		Center->IterModuleBeginPlay(Center);
		//ִֻ�е�һ֡
		IsBeginPlay = true;
	}
	else
		//��������Tick����
		Center->IterModuleTick(Center, DeltaTime);
}

bool ADDDriver::RegisterToModule(IDDOO* ObjectInst)
{
	//��������ģ�����ע��
	return Center->RegisterToModule(ObjectInst);
}

#if WITH_EDITOR

void ADDDriver::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	if (PropertyChangedEvent.Property && PropertyChangedEvent.Property->GetFName() == GET_MEMBER_NAME_CHECKED(ADDDriver, ModuleType))
		Center->IterChangeModuleType(Center, ModuleType);
}

#endif

void ADDDriver::ExecuteFunction(DDModuleAgreement Agreement, DDParam* Param)
{
	Center->AllotExecuteFunction(Agreement, Param);
}

void ADDDriver::ExecuteFunction(DDObjectAgreement Agreement, DDParam* Param)
{
	Center->AllotExecuteFunction(Agreement, Param);
}
