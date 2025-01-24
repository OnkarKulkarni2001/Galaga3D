# Game Engine Frameworks & Patterns Project 01

---

## Team Members:

Onkar Parag Kulkarni (Student ID: 1286580)

Deep Shah (Student ID: 1297198)

---

### Game Controls:

TAB: To start the game

RIGHT ARROW: Move player to right

LEFT ARROW: Move player to left

SPACEBAR: Fire player projectiles

---

### Instructions To Build:

Just run the .sln file and run build.

---

### Challenges faced:

We have different type of objects in different type of vectors, like we had same model in 7 orientations so I actually added those 7 models to same vector for same type of object.

We have actually loaded all models to same vector but it was harder to access the models through this as we needed to check index of every model from scenefile and then we did further things but as it was hard we shifted to the approach of having different vectors for different type of model	s.

We used only vertical orientations of projectiles, players and enemies. As we kept fixed orientation of player and enemies, if we had more time to implement the movement of the aliens in curves then we would have used other orientations as well.

Biggest issue we faced while doing this was with collision, that the enemies were at different positions but the collision was getting detected only at a specific position, so then we realized that even after calculating bounding spheres and setting positions of bounding spheres with the positions of enemies, those weren’t colliding at right positions. So then we realized we need to have matrix multiplication with the physics meshes as well and implemented that and everything worked really well after this.

While implementing the moth aliens turn blue after one hit, it was kinda easy as we had setters for the alien types.

As we were trying to delete the projectiles which hit the aliens, we implemented a small check whether this projectile exists in our projectiles to delete vector or not, without this check, same projectile location was getting deleted again and again and this was throwing some kind of error.

---

### THANK YOU!
