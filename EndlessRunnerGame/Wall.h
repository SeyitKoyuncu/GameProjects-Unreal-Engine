// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Wall.generated.h"

/**
 * 
 */
UCLASS()
class RUNNERGAME_API AWall : public ABasePawn
{
	GENERATED_BODY()

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	float Speed = 2;
	void Moved();
	
};
