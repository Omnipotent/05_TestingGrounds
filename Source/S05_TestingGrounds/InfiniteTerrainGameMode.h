// Copyright Nicholas Wilkie 2017

#pragma once

#include "S05_TestingGroundsGameMode.h"
#include "InfiniteTerrainGameMode.generated.h"

/**
 * 
 */
UCLASS()
class S05_TESTINGGROUNDS_API AInfiniteTerrainGameMode : public AS05_TestingGroundsGameMode
{
	GENERATED_BODY()

public:
	AInfiniteTerrainGameMode();

	UFUNCTION(BlueprintCallable, Category = "Bounds Pool")
	void PopulateBoundsVolumePool();

protected:
	/** Nav Mesh Bounds Volume Pool */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pool")
	class UActorPool* NavMeshBoundsVolumePool;
	

private:
	void AddToPool(class ANavMeshBoundsVolume *VolumeToAdd);
};
