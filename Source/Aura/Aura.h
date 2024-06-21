

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemBlueprintLibrary.h"

#define RETURN_IF_NULL(Object)		if (Object == nullptr)		{ return; }
#define RETURN_IF_NOT_NULL(Object)	if (Object != nullptr)		{ return; }
#define RETURN_IF_VALID(Object)		if (IsValid(Object))		{ return; }
#define RETURN_IF_NOT_VALID(Object)	if (!IsValid(Object))		{ return; }
#define RETURN_IF_TRUE(Expression)	if ((Expression) == true)	{ return; }
#define RETURN_IF_FALSE(Expression) if ((Expression) == false)	{ return; }

#define RETURN_IF_NULL_ENSURE(Object)		if (Object == nullptr)		{ ensure(false); return; }
#define RETURN_IF_NOT_NULL_ENSURE(Object)	if (Object != nullptr)		{ ensure(false); return; }
#define RETURN_IF_VALID_ENSURE(Object)		if (IsValid(Object))		{ ensure(false); return; }
#define RETURN_IF_NOT_VALID_ENSURE(Object)	if (!IsValid(Object))		{ ensure(false); return; }
#define RETURN_IF_TRUE_ENSURE(Expression)	if ((Expression) == true)	{ ensure(false); return; }
#define RETURN_IF_FALSE_ENSURE(Expression)	if ((Expression) == false)	{ ensure(false); return; }

#define RETURN_VALUE_IF_NULL(Object, Value)			if (Object == nullptr)		{ return Value; }
#define RETURN_VALUE_IF_NOT_NULL(Object, Value)		if (Object != nullptr)		{ return Value; }
#define RETURN_VALUE_IF_VALID(Object, Value)		if (IsValid(Object))		{ return Value; }
#define RETURN_VALUE_IF_NOT_VALID(Object, Value)	if (!IsValid(Object))		{ return Value; }
#define RETURN_VALUE_IF_TRUE(Expression, Value)		if ((Expression) == true)	{ return Value; }
#define RETURN_VALUE_IF_FALSE(Expression, Value)	if ((Expression) == false)	{ return Value; }

#define RETURN_VALUE_IF_NULL_ENSURE(Object, Value)		if (Object == nullptr)		{ ensure(false); return Value; }
#define RETURN_VALUE_IF_NOT_NULL_ENSURE(Object, Value)	if (Object != nullptr)		{ ensure(false); return Value; }
#define RETURN_VALUE_IF_VALID_ENSURE(Object, Value)		if (IsValid(Object))		{ ensure(false); return Value; }
#define RETURN_VALUE_IF_NOT_VALID_ENSURE(Object, Value)	if (!IsValid(Object))		{ ensure(false); return Value; }
#define RETURN_VALUE_IF_TRUE_ENSURE(Expression, Value)	if ((Expression) == true)	{ ensure(false); return Value; }
#define RETURN_VALUE_IF_FALSE_ENSURE(Expression, Value)	if ((Expression) == false)	{ ensure(false); return Value; }

class UAbilitySystemComponent;
DECLARE_LOG_CATEGORY_EXTERN(LogHighlight, Log, All)

#define ECC_HIGHLIGHT ECC_GameTraceChannel1


template<class T>
T* GetComponent(AActor* From)
{
	return IsValid(From) ? From->GetComponentByClass<T>() : nullptr;
}

template<class T = UAbilitySystemComponent>
T* GetAbilitySystemComponent(AActor* From)
{
	return Cast<T>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(From));
}