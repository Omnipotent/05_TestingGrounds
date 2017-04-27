// Copyright Nicholas Wilkie 2017

#include "S05_TestingGrounds.h"
#include "ActorPool.h"


// Sets default values for this component's properties
UActorPool::UActorPool()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

AActor* UActorPool::Checkout()
{
	UE_LOG(LogTemp, Warning, TEXT("[%s] Checkout."), *GetName());
	return nullptr;
}

void UActorPool::Return(AActor* ActorToReturn)
{
	if (ActorToReturn == NULL)
	{
		UE_LOG(LogTemp, Warning, TEXT("[%s] Returned null actor"), *GetName());
		return;
	}
	UE_LOG(LogTemp, Warning, TEXT("[%s] Actor Returned: {%s} "), *GetName(), *ActorToReturn->GetName());
}

void UActorPool::Add(AActor* ActorToAdd)
{
	if (ActorToAdd == NULL)
	{
		UE_LOG(LogTemp, Warning, TEXT("[%s] Added null actor"), *GetName());
		return;
	}
	UE_LOG(LogTemp, Warning, TEXT("[%s] Actor added: {%s} "), *GetName(), *ActorToAdd->GetName());
}
