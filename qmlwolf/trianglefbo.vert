#version 330
layout(location = 0) in vec3 position;
layout(location = 1) in vec3 color;
out vec4 vColor;

// ---- CAMERA ----
uniform mat4 projection;  //Orthogonal vs Projection etc.
uniform mat4 view;        //Where is the camera and looking at.

// ---- THE UNDER RENDERING MODEL ----
uniform mat4 model;             //Scale => Rotation => Position.


void main()
{
  gl_Position = projection * view * model * vec4(position, 1.0);
  vColor = vec4(color, 1.0);
}
