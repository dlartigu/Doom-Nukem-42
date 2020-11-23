# Doom-Nukem-42
Based on advanced raycasting recreate the first Wolfenstein/Doom experience in C using a Library 'just to display the pixels', everything needs to be running on a CPU. (in 1992 GPU were a dream)
Easy to compile, to run it on make just 'make', and on Linux 'sudo make'!

## **What I have done on this project ?**

**MAP**: The parsing was'nt that hard, even if the map is a really big deal, I questionned myself about getting all the informations needed, wall size, floor, ceiling texture, sprite, actions etc... in the game the map can't be over 50 * 50 but I've tryed with 1000 * 1000 and it's working.
IE: 00620120

**Engine**: Based on raycasting I've tryed to do my best to add what some call 'impossible with raycast', the movements including jumping, crouching, flying, diving, diing, different wall height. This was very challenging as you need to try everything in order to complete correctly some movements like the crouch.
(Thanks to nboute for the visual fix on the wall height)

**Game Design / Level Design**: I wanted this project to be like I could immagine it, I wrote the story, I determined what will be in the game, how we would have play it, how everything would be, from level 1 to the final boss, including the arcade mode. I want the player to be forced to seek into the entire map to go to the next level. I wanted every level to look totally different, to sound totally different, wich is why we have 3 different atmospheres and an arena to beat the boss.
I also wanted an Arcade mode like the old doom, just for fun you know!

**Visual**: I've made most of the visual that you can see in this game (except for the sprite, thanks for the doom sprite database), if there is a visual that isn't from me, then I've reworked it on Photoshop/Gimp. I've could take textures from a database, but the game wouldn't match my vision.

**Audio**: In order to match my vision of this game, I've searched for days to get the perfect matching sound design, all sound design are from royalty free database.

**Team Management**: At the beggining we were 2, then 3, then 4. It was tough, as in a huge project like this you need someone to lead if you want the project to be finished someday. You need, to call them, organize meetings and put some pressure on you team mates.

**Project Organization**: this part match the previous one, because you can't lead a project without being very organized. You need to know what needs to be done first in order to achieve the next goal. Wich is why we could work all together without interferring in others parts.

------

## **How to play ?**

It's relatively common, here are the main ones (you can see them in the settings menu)

| ACTION | KEY             |
| ------ | --------------- |
| Fire   | Mouse Left Clic |
| Reload | R               |
| Move   | WASD            |
| Jump   | Spacebar        |
| Crouch | Left CTRL       |

------

## **Wanna see some gameplay footage ?**

In the menu selection you can play the story or try to high score in arcade mode.
If you have a very powerfull computer you can try to run the game in 1080p (or higher) with every settings maxed. You'll see a big texture difference!

![Low vs Hgh](https://github.com/dlartigu/Doom-Nukem-42/blob/main/gif/lowvshigh.png)







