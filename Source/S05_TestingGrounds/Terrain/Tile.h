// Copyright Nicholas Wilkie 2017

#pragma once

#include "GameFramework/Actor.h"
#include "Tile.generated.h"

USTRUCT()
struct FSpawnPosition
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY()
	FVector Location;

	UPROPERTY()
	float Rotation;

	UPROPERTY()
	float Scale;
};

USTRUCT()
struct FActorSpawnInfoStruct
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	int MinSpawn;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	int MaxSpawn;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	float MinScale;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	float MaxScale;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	float Radius;

	FActorSpawnInfoStruct()
	{
		MinSpawn = 1;
		MaxSpawn = 1;
		MinScale = 1;
		MaxScale = 1;
		Radius = 500;
	}
};


class UActorPool;

UCLASS()
class S05_TESTINGGROUNDS_API ATile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATile();

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void PlaceActors(TSubclassOf<AActor> ToSpawn, FActorSpawnInfoStruct SpawnInfo);
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	UPROPERTY(EditDefaultsOnly, Category = "Navigation")
	FVector NavigationBoundsOffset;

	UPROPERTY(EditDefaultsOnly, Category = "Spawning")
	FVector MinExtent;

	UPROPERTY(EditDefaultsOnly, Category = "Spawning")
	FVector MaxExtent;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Pool")
	void SetPool(UActorPool* Pool);

private:
	void PositionNavMeshBoundsVolume();

	TArray<FSpawnPosition> RandomSpawnPositions(int MinSpawn, int MaxSpawn, float Radius, float MinScale, float MaxScale);

	bool FindEmptyLocation(FVector& OutLocation, float Radius);

	UFUNCTION(BlueprintCallable, Category = "Spawn")
	void PlaceActor(TSubclassOf<AActor> ToSpawn, FSpawnPosition SpawnPosition);

	bool CanSpawnAtLocation(FVector Location, float Radius);
	
	UActorPool* Pool;

	AActor* NavMeshBoundsVolume;
};
