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
	return nullptr;
}

void UActorPool::Return(AActor* ActorToReturn)
{

}

void UActorPool::Add(AActor* ActorToAdd)
{

}
