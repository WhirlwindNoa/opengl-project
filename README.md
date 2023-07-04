# random graphics application made on c++

this was supposed to be a raycasting engine, however i lost motivation. maybe i will continue one day
uses:
- GLFW
- GLAD

# update logs

version 0.0.1

- replaced std::vectors with custom struct vector objects (Vector3f, Vector3i, Vector2f, Vector2i)
- minimal drawing API was added (g_RenderRect, g_RenderLine)
- started working on Ray Casting and optimizing trigonometry
- replaced standard library cos and sin functions to cossin_cordic where possible
- added one more tile type (White and Red)

![alt text](https://cdn.discordapp.com/attachments/827493056718045195/1037456170845225011/unknown.png)
