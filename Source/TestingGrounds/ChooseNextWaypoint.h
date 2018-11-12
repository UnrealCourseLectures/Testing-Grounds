// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "ChooseNextWaypoint.generated.h"

/**
 * 
 */
UCLASS()
class TESTINGGROUNDS_API UChooseNextWaypoint : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Patrol")
	struct FBlackboardKeySelector Index;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Patrol")
	struct FBlackboardKeySelector Waypoint_Location;
	
	AActor* Local_PatrolPoints[4];

private:
	void GetPatrolPoints();
	int SetNextWaypoint();
	void CycleNextIndex(int Index);
};
