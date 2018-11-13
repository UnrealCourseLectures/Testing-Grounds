// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PatrollingComponent.generated.h"

/*
 * Gives the AI, Patrol Information to Follow -- and -- HELPS Choose Next Waypoint.
*/
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TESTINGGROUNDS_API UPatrollingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	TArray<AActor*> GetPatrolRoutes() const;

private:
	UPROPERTY(EditInstanceOnly, Category = "Patrol Routes")
	TArray<AActor*> PatrolRoutes;
};
