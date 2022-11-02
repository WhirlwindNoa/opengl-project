# A ray casting engine written on C++

This is a ray casting application on C++ which takes heavy use of OpenGL libraries for C++ such as
- GLFW
- GLAD

# Update logs

Version 0.0.1

- Started logging versions
- Replaced std::vectors with custom struct vector objects (Vector3f, Vector3i, Vector2f, Vector2i)
- Minimal drawing API was added (g_RenderRect, g_RenderLine)
- Started working on Ray Casting and optimizing trigonometry
- Replaced standard library cos and sin functions to cossin_cordic where possible
- Added one more tile type (White and Red)

![alt text](https://cdn.discordapp.com/attachments/827493056718045195/1037456170845225011/unknown.png)
