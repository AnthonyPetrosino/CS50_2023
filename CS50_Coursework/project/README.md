# Seals
#### Video Demo: https://youtu.be/T9w4_WzY7Gs
#### Description:

For my final project, I wanted to create a 2D platformer game similar to Mario (inspired by the Mario
problem sets). However, I aimed to implement the programming techniques I learned, so instead
of using Scratch, I used Unity. In Unity, I had to learn the basics of C# (which was more different
from C than I thought it would be), player movement physics (with friction and gravity), map design,
and many other mechanics.

In my game, you play as a penguin in an arctic land, sliding and jumping across obstacles. There are
enemies that are on fire who will make you lose a life if you touch them, and there are fish to collect
to advance your score. Although I did not have enough time to implement many features that I wanted to
(such as throwing snowballs to kill enemies, displaying fish/life counter, and creating more levels), my
scripts allow for such features to be implemented in the future as they do record the number of fish
and lives, along with allowing for easy scene swapping upon the completion of the level.

Scripts that I implemented:


The "AnimatedSprite" script animates a game object by cycling through a set of sprites. It requires a
"SpriteRenderer" component and is equipped with an array of sprites and a frame rate variable. The script
automatically animates the sprite sequence when the GameObject is enabled, utilizing the specified frame
rate. The animation loop is managed through the "Animate" method, incrementing the frame index and updating
the SpriteRenderer accordingly, with a check to loop back to the first sprite when reaching the end of the
array. Additionally, the script cancels the animation when the GameObject is disabled to ensure proper cleanup.

The "GameManager" script is responsible for managing game states and progression. It features an Instance to
ensure a single instance of the GameManager throughout the game. Key variables include world, stage, lives,
and Fish (representing number of collected fish). The script handles the initialization of a new game, loading
levels, managing game over scenarios, and advancing to the next level. It also incorporates methods to reset levels,
add fish to the player's score, and add extra lives. This allows for easy implementation of next levels.

The "EntityMovement" script is designed to control the movement of an entity with a Rigidbody2D component. It requires
the GameObject to have a Rigidbody2D component attached. Key features include defining speed and movement direction,
managing Rigidbody2D physics interactions, handling visibility events, and changing the entity's direction upon collision
with obstacles. The script also adjusts the rotation of the entity based on its movement direction. The use of OnBecameVisible
and OnBecameInvisible allows objects to become visible only when they enter the camera's scope (I made it for enemies).
The FixedUpdate method handles the continuous movement of the entity, taking into account gravity, collisions, and direction
changes. Additionally, the script puts the Rigidbody2D to sleep when disabled to prevent crazy physics stuff from happening.

The "DeathAnimation" script in Unity is designed to handle the animation and visual effects associated with the death of the
player. Key features include the use of a SpriteRenderer component, the ability to specify a deadSprite for the death animation,
and the option to adjust the sorting order of the sprite. The script utilizes Coroutine to animate the GameObject's movement
upwards, simulating a jump or floating effect, making for a comical death look. Additionally, the script provides functionality
to disable physics components, such as colliders and Rigidbody2D, to ensure the GameObject's immobility during the death animation
and to allow it to fall through the world before reseting. The script also takes care of enabling and disabling these features when
the GameObject is enabled or disabled.

The "Player" script is responsible for managing player-related functionalities. It features a CapsuleCollider2D and a
DeathAnimation component, accessed through the Awake method. The script exposes a property, 'dead,' indicating whether the
death animation is currently enabled. The script provides a Hit method, serving as a trigger for the player's death, which,
in turn, calls the Death method. The Death method sets the death animation to be enabled and initiates a level reset through the
GameManager's ResetLevel method with a delay of 3 seconds. This script centralizes essential player interactions, including handling
hits, managing death animations, and coordinating level resets within the game.

The "DeathBarrier" script is designed to handle collisions with a GameObject equipped with a BoxCollider2D component. When a collision occurs,
the script checks if the colliding object has the "Player" tag. If it does, the player's GameObject isdeactivated, triggering a level
reset through the GameManager's ResetLevel method with a delay of 3 seconds, allowing for a comical falling to death feel. If the colliding
object does not have the "Player" tag, it is immediately destroyed. This script serves as a boundary within the game, enforcing consequences for
the player's interaction, such as resetting the level upon contact with the death barrier.

The "Cave" script is designed to handle interactions with a cave area, which is the level's exit. When a GameObject with the tag "Player" enters
the trigger area of the cave, a coroutine is initiated to move the player towards the specified destination within the cave, making it seem like
the penguin is entering. Additionally, the script temporarily disables the PlayerMovement component to halt the player's control during the sequence.
The LevelCompleteSequence coroutine gradually moves the player to the cave's middle position, deactivates the player's GameObject, introduces a
2-second delay, and then triggers the GameManager to load the next level based on the specified world and stage. This allows for easy progression
from level to level.

The "PowerUp" script is designed to handle interactions with power-up objects. The power-up has an associated type, defined by the "Type" enum,
with options for "Fish" and "Snowball." When a GameObject with the tag "Player" enters the trigger area defined by the script, the OnTriggerEnter2D
method is triggered. In response, the Collect method is called, checking the type of the power-up. Currently, the script supports the "Fish" type,
and upon collection by the player, it triggers the GameManager to add a fish to the player's score. I am going to implement the "Snowball" type to
be a sort of ammo for the penguin, allowing it to throw snowballs to extinguish crabs. After being picked up, the power-up GameObject is destroyed,
removing it from the game. This script allows for the collection of different types of power-ups by the player, with the current implementation only
handling the "Fish" type.


I also have prefabs for the background, the penguin, the fish, the crabs, the cave/exit and the ground, allowing me to easily design more levels.


I hope you enjoy! Happy holidays,

Anthony Petrosino
