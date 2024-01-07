# Type a script or drag a script file from your workspace to insert its path.
echo ">>> compiling shaders"
echo ">>> compiling shader.vert..."
glslc resources/shaders/shader.vert -o resources/shaders/vert.spv
echo ">>> compiling shader.frag"
glslc resources/shaders/shader.frag -o resources/shaders/frag.spv
echo ">>> finished"
