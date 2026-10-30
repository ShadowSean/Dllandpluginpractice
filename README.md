# Game Engine Design: Project Check-In

## Singleton: Custom Graphics

This singleton is responsible for simplifying the process of changing the GameUserSettings of the game and the editor.

<img height="400" alt="image" src="https://github.com/user-attachments/assets/f0f4f851-155c-410e-bfde-fa986a986a31" />
<img height="400" alt="image" src="https://github.com/user-attachments/assets/d8b2da4a-2928-4713-b84a-df77131c6b36" />

## Singleton: Game Awards System

This singleton is responsible for distributing game awards to the player.
<img height="300" alt="image" src="https://github.com/user-attachments/assets/06694812-289b-4cd2-8830-de618f76246d" />

## Factory & Singleton: Audio Manager

This factory+singleton, that is referenced by the Master Game Instance, and accessible from anywhere in the code, is responsible for allowing and managing the playback of audio, and reducing audio overlap. It is also considered a factory, due to the fact that it spawns in the audio objects without knowing what sound it is.
[insert img here]

## Factory: PCG Room Generator

This factory is responsible for spawning in and customizing the layout of the furtniture of the rooms.

## Factory: Evidence Manager (unimplemented)

This factory (which hasn't yet been implemented) would've been responsible for spawning in and managing the lifecycles of the specific in-game items that tie in to the evidence necessary to solve the crime.
