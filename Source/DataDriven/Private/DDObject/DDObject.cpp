// Fill out your copyright notice in the Description page of Project Settings.

#include "DDObject.h"







void UDDObject::DDRelease()
{
	//��Root�Ƴ�
	RemoveFromRoot();
	//׼��������Դ
	ConditionalBeginDestroy();
}
