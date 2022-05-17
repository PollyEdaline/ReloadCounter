Reload Counter
====
All this does currently is display your current remaining full reloads above your ammo counter. I made this for my partner, who has mild OCD (the actual disorder). In the future, I would like to change this to override the total ammo display, but I have very limited programming/blueprint knowledge. I made this for accessibility reasons.

I could really use some help with improving this mod. It was already a struggle to get just this working, and I am having a lot of trouble implementing a few things I want to add. Most notably, I would like it to override the total ammo by default, with a config option to instead show it as a separate UI element. I have tried to figure this out on my own but it just won't work for me. I am out of ideas. If someone can please help, my Discord is Pollychan#8281, or you can message me here on mod.io. Thank you.

Github link: https://github.com/PollyEdaline/ReloadCounter

## Known issues

These are all the issues with the mod that I know about. Sadly, I don't really know how to fix most of them.

- Does not correctly obey UI scale options. Will go off the screen above 100% UI scale.
- When switching to a weapon without magazines/etc, the counter will display the count of the last weapon that had a count. It will update properly when switching to a weapon with a count.
- There are no config options currently. A few that I would like to add, but don't know how:
  - Ability to switch between overriding the total ammo display, or displaying separately
  - Ability to move and resize separated display
  - Ability to rename separated display
  - Ability to round reload count up or down (currently, it rounds down)