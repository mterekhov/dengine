#version 450

layout(binding = 0) uniform ProjectionObject {
    mat4 view;
    mat4 proj;
} projectionObject;

layout(location = 0) in vec3 inPosition;
layout(location = 1) in vec2 inTexCoord;

layout(location = 2) in vec3 instanceTranslation;
layout(location = 3) in vec3 instanceRotation;
layout(location = 4) in vec3 instanceScale;

layout(location = 0) out vec2 fragTexCoord;

void main() {
    mat3 mx, my, mz;
    
    // rotate around x
    float sinValue = sin(instanceRotation.x);
    float cosValue = cos(instanceRotation.x);
    mx[0] = vec3(cosValue, sinValue, 0.0);
    mx[1] = vec3(-sinValue, cosValue, 0.0);
    mx[2] = vec3(0.0, 0.0, 1.0);
    
    // rotate around y
    sinValue = sin(instanceRotation.y);
    cosValue = cos(instanceRotation.y);
    my[0] = vec3(cosValue, 0.0, sinValue);
    my[1] = vec3(0.0, 1.0, 0.0);
    my[2] = vec3(-sinValue, 0.0, cosValue);
    
    // rot around z
    sinValue = sin(instanceRotation.z);
    cosValue = cos(instanceRotation.z);
    mz[0] = vec3(1.0, 0.0, 0.0);
    mz[1] = vec3(0.0, cosValue, sinValue);
    mz[2] = vec3(0.0, -sinValue, cosValue);
    
    mat3 rotMat = mz * my * mx;

    vec4 locPos = vec4(inPosition.xyz * rotMat, 1.0);
    vec4 pos = vec4((locPos.xyz * instanceScale) + instanceTranslation, 1.0);

    gl_Position = projectionObject.proj * projectionObject.view * pos;
    fragTexCoord = inTexCoord;
}
