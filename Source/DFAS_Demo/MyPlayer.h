#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "MyPlayer.generated.h"



UCLASS() // Macro primordial - hereda de clase UObject

class DFAS_DEMO_API AMyPlayer : public ACharacter{ // AMyPlayer, ACharacter - heredan de clase AActor

	GENERATED_BODY() // Macro primordial 

public:

	// Establece valores por defecto para las propiedades del Character.
	AMyPlayer();// Constructor.

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		UCameraComponent* FollowCamera;


protected:
	// Llamada al comienzo del juego o en cada spawneo.
	virtual void BeginPlay() override;

	// Funci�n Landed en Character.h
	virtual void Landed(const FHitResult& Hit) override;

public:	
	// LLamada cada frame.
	virtual void Tick(float DeltaTime) override;

	// Llamada para enlazar funciones al input.
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Declaraciones de funciones miembro para movimiento.
	void MoveForward(float amount);
	void MoveRight(float amount);

	UFUNCTION()
		void DoubleJump();
	UPROPERTY()
		int DoubleJumpCounter; // Para el n�mero de saltos que podr� realizar.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float JumpHeight;   // Para la altura de dichos saLtos.


	UFUNCTION()
		void Walk();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Walkingspeed;

	UFUNCTION()
		void Sprint();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Runningspeed;


	UFUNCTION()
		void Dash();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float DashDistance;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float DashCooldown;
	UPROPERTY()
		bool CanDash;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float DashStop;

	UFUNCTION()
		void StopDashing();
	UPROPERTY()
		FTimerHandle Unused;

	UFUNCTION()
		void ResetDash();

};

/* En este archivo HEADER se incluyen las macros, 
de las cuales Unreal Engine hace uso masivo y
que permiten integrar en el proyecto una gran 
cantidad de c�digo pre-escrito permitiendo as�
que el proyecto est� totalmente integrado tanto
en Visual Studio como en Unreal.

Los cambios en  cualquiera de los dos se 
aplicar�n inmediatamente en ambos editores. */

/* Macro: UCLAS 
Encargada de que el c�digo est� 
totalmente disponible en UE. */

/* Macro: GENERATED_BODY() 
Encargada de copiar y pegar el 
c�digo que UE necesita para que 
su clase funcione correctamente 
como una clase UE4. */