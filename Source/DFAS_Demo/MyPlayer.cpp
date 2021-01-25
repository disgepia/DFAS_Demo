#include "MyPlayer.h"


/***********************************  CONSTRUCTOR  ****************************************/
AMyPlayer::AMyPlayer(){

	//Establecer valores por defecto.
	// Activar la llamada a función Tick() en cada frame.
	PrimaryActorTick.bCanEverTick = true;

	// No se permite rotar al Controller.
	bUseControllerRotationPitch = false; // X
	bUseControllerRotationYaw = false; // Y
	bUseControllerRotationRoll = false; // Z

	// Rotar al personaje hacia la dirección en la que se está moviendo.
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 900.0f, 0.0f); // X,Y,Z
	GetCharacterMovement()->JumpZVelocity = 600.f;
	// Qué tanto se puede controlar al personaje mientras está en el aire.
	GetCharacterMovement()->AirControl = 0.1f; 

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent); // Se enlaza a CapsuleComponent en BP_MyPlayer

	CameraBoom->TargetArmLength = 300.0f;
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);

	FollowCamera->bUsePawnControlRotation = false;

}
/***********************************  CONSTRUCTOR  ****************************************/

// Llamada al comienzo del juego o en cada spawneo.
void AMyPlayer::BeginPlay(){

	Super::BeginPlay();
	
}

// LLamada cada frame.
void AMyPlayer::Tick(float DeltaTime){

	Super::Tick(DeltaTime);

}
// Llamada para enlazar funciones al input.
void AMyPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {

	// De lo que hereda de la clase padre
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	/*Se le añade el código para que busque
	 los enlaces a los ejes del input.*/
	check(PlayerInputComponent); // Comprobar contenido configurado en el editor de UE.
	// Método BindAxis para acceder a los valores de Forward/Right.
	// This para indicar que la función se ejecuta desde el objeto que la llame.
	// 3er parámetro - pasar la llamada a las funciones de la clase AMyPlayer definidas en header
	PlayerInputComponent->BindAxis("Forward", this, &AMyPlayer::MoveForward);
	PlayerInputComponent->BindAxis("Right", this, &AMyPlayer::MoveRight);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AMyPlayer::DoubleJump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAxis("Yaw", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("Pitch", this, &APawn::AddControllerPitchInput);

	JumpHeight = 600.f;
}

void AMyPlayer::MoveForward(float amount) {

	/* No entrará en el cuerpo de está función
	si Controller no está configurado 
	O si la cantidad a mover es igual a 0. */
	if (Controller && amount) { // Detecta que el Input esté accionado y que haya movimiento.

		FRotator Rotation = Controller->GetControlRotation();
		FRotator YawRotation(0.0f, Rotation.Yaw, 0.0f);

		FVector direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

		//FVector fwd = GetActorForwardVector();
		AddMovementInput(direction, amount);
	}
}

void AMyPlayer::MoveRight(float amount) {

	if (Controller && amount) { 

		FRotator Rotation = Controller->GetControlRotation();
		FRotator YawRotation(0.0f, Rotation.Yaw, 0.0f);

		FVector direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		AddMovementInput(direction, amount);
	}
}

void AMyPlayer::DoubleJump(){

	if (DoubleJumpCounter <= 1) {
		ACharacter::LaunchCharacter(FVector(0,0, JumpHeight), false, true);
		DoubleJumpCounter++;
	}
}

void AMyPlayer::Landed(const FHitResult& Hit) {
	DoubleJumpCounter = 0;
}


