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

One Blueprint to Rule Them All! Creating a Global Music Manager in Unreal Engine 5 - Thank Me Later: https://youtu.be/bt3lXwztrO4
![Blueprints made with above ref + AI Debugging](<Screenshot 2026-10-29 211600.png>)
!**No AI was used for the implementation inside of the final project. Only in the test project as shown in the image above**!

## Factory: PCG Room Generator

We use **PCG and Blueprints** to furnish a hotel room. It places a bed, wardrobe, desk, lamp, and bedside tables from placement rules and a random seed, rather than choosing from a set of premade layouts.

### How it works

The room Blueprint supplies the floor and room bounds. The PCG graph samples candidate positions on the floor, tests different orientations, and checks space around each item against walls, the doorway, and furniture already chosen. It then selects valid positions using the seed. Changing the seed can produce a different arrangement; resizing the room gives the graph a different area to sample.

The **Factory Method** part is used to create the furniture. PCG spawns a furniture Factory Blueprint at each chosen position. Each specific factory creates its matching furniture Product Blueprint through the shared factory interface. This keeps the placement rules separate from the furniture that is created.

### PCG graph

<img width="1105" height="517" alt="Screenshot 2026-10-29 205733" src="https://github.com/user-attachments/assets/15e9e2fb-e289-40db-ac20-8cc4ac3cd81d" />
<img width="1067" height="396" alt="Screenshot 2026-10-29 205739" src="https://github.com/user-attachments/assets/4e97bc86-c29e-46b2-8b27-adb70bd075be" />
<img width="4311" height="4368" alt="Room_Factory_Diagram_4K" src="https://github.com/user-attachments/assets/f664e1bd-8604-4b53-bece-6c67340d44af" />

**AI assistance:** I ( Isshan ) used AI to find and understand the PCG nodes needed to check candidate furniture positions against world collision. I then connected and tested the World Volumetric Query with Intersection in my room generator to filter out blocked positions.

<img width="629" height="201" alt="Screenshot 2026-10-29 180618" src="https://github.com/user-attachments/assets/7c34c1ed-b642-427e-8a28-644693a43625" />


## Factory: Evidence Manager (unimplemented)

This factory (which hasn't yet been implemented) would've been responsible for spawning in and managing the lifecycles of the specific in-game items that tie in to the evidence necessary to solve the crime.


## Future Implementations

**Singleton:** One shared Hotel Manager Blueprint will coordinate both room and floor generation.

**Factory:** Room factories will create different room types, such as a normal room and a scenic room. The factory system could later expand to floor layouts and the hotel exterior.

**Plugin and DLL:** We plan to package the finished PCG tool as a reusable plugin for other Unreal projects. We are still deciding what additional functionality it should include.
