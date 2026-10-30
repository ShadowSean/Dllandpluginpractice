# Game Engine Design: Project Check-In

## Singleton: Custom Graphics

This singleton is responsible for simplifying the process of changing the GameUserSettings of the game and the editor.

<img height="400" alt="image" src="https://github.com/user-attachments/assets/f0f4f851-155c-410e-bfde-fa986a986a31" />
<img height="400" alt="image" src="https://github.com/user-attachments/assets/d8b2da4a-2928-4713-b84a-df77131c6b36" />

## Singleton: Game Awards System

This singleton is responsible for distributing game awards to the player.
<img height="300" alt="image" src="https://github.com/user-attachments/assets/06694812-289b-4cd2-8830-de618f76246d" />

## Factory & Singleton: Audio Manager


This factory+singleton, that is referenced by the Master Game Instance which creates only one instance of BP_AudioManager on initialization, and is accessible from anywhere in the code, is responsible for allowing and managing the playback of audio, and reducing audio overlap. It is also considered a factory, due to the fact that it spawns in the audio objects without knowing what sound it is.

The original prototyping and concept used the YouTube video linked below. Claude AI was used to check program logic and debug the initial prototype of the manager inside of a different project. To expand upon the content of the sources, the Factory framework was implemented by abstracting the reference outside of BP_AudioManager and playing the reference inside of the manager, as well as functionality for crossfading between tracks using a reference to the currently playing song to ensure music and SFX don't overlap while leaving room for a fade out during scene transitions rather than a harsh transition.

![BP_AudioManager](<Screenshot 2026-10-29 205941.png>)
![Master_GameInstance_Manager](<Screenshot 2026-10-29 205947.png>)
![Level Blueprint](<Screenshot 2026-10-29 210051.png>)

![Onehttps://youtu.be/bt3lXwztrO4

## Factory: PCG Room Generator

This factory is responsible for spawning in and customizing the layout of the furtniture of the rooms.

## Factory: Evidence Manager (unimplemented)

This factory (which hasn't yet been implemented) would've been responsible for spawning in and managing the lifecycles of the specific in-game items that tie in to the evidence necessary to solve the crime.
