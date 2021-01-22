#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyPlayer.generated.h"

UCLASS() // Macro primordial - hereda de clase UObject

class DFAS_DEMO_API AMyPlayer : public ACharacter{ // AMyPlayer, ACharacter - heredan de clase AActor

	GENERATED_BODY() // Macro primordial 

public:

	// Establece valores por defecto para las propiedades del Character.
	AMyPlayer();

protected:
	// Llamada al comienzo del juego o en cada spawneo.
	virtual void BeginPlay() override;

public:	
	// LLamada cada frame.
	virtual void Tick(float DeltaTime) override;

	// Llamada para enlazar funciones al input.
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Declaraciones de funciones miembro para movimiento.
	void MoveForward(float amount);
	void MoveRight(float amount);

};

/* En este archivo HEADER se incluyen las macros, 
de las cuales Unreal Engine hace uso masivo y
que permiten integrar en el proyecto una gran 
cantidad de código pre-escrito permitiendo así
que el proyecto esté totalmente integrado tanto
en Visual Studio como en Unreal.

Los cambios en  cualquiera de los dos se 
aplicarán inmediatamente en ambos editores. */

/* Macro: UCLAS 
Encargada de que el código esté 
totalmente disponible en UE. */

/* Macro: GENERATED_BODY() 
Encargada de copiar y pegar el 
código que UE necesita para que 
su clase funcione correctamente 
como una clase UE4. */