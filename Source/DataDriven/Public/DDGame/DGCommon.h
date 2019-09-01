// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DGTypes.h"
#include "DGCommon.generated.h"

namespace DGH
{
	//���������н�, ���� 0 - 360 ��, ��һ������Ϊ�궨����, ��˳ʱ�뷽�����
	FORCEINLINE float CalcVectorAngle(FVector ArcVec, FVector DesVec)
	{
		ArcVec.Normalize();
		DesVec.Normalize();
		float ResAngle = (FVector::CrossProduct(ArcVec, DesVec).Z > 0 ? 1.f : -1.f) * FMath::RadiansToDegrees(FMath::Acos(FVector::DotProduct(ArcVec, DesVec)));
		if (ResAngle < 0.f) ResAngle += 360.f;
		return ResAngle;
	}
	FORCEINLINE float CalcVector2DAngle(FVector2D ArcVec, FVector2D DesVec)
	{
		ArcVec.Normalize();
		DesVec.Normalize();
		float ResAngle = (FVector2D::CrossProduct(ArcVec, DesVec) > 0 ? 1.f : -1.f) * FMath::RadiansToDegrees(FMath::Acos(FVector2D::DotProduct(ArcVec, DesVec)));
		if (ResAngle < 0.f) ResAngle += 360.f;
		return ResAngle;
	}
}


/**
 * 
 */
UCLASS()
class DATADRIVEN_API UDGCommon : public UObject
{
	GENERATED_BODY()
	
public:

	static UDGCommon* Get();
	
private:

	static UDGCommon* DGInst;
	
};


