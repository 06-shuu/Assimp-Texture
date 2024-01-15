#ifndef MODEL_H
#define MODEL_H

#include "ShaderProgram.h"
#include <vector>
#include <string>
#include "Mesh.h"
 
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

using namespace std;
class Model
{
public:
    vector<Texture> textures_loaded;
    Model(string path); 
    void Draw(ShaderProgram& shader);
private:
    // model data
    vector<Mesh> meshes;
    string directory;
     
    void loadModel(string path);
    void processNode(aiNode* node, const aiScene* scene);
    Mesh processMesh(aiMesh* mesh, const aiScene* scene);  
    vector<Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType type, string typeName);
};

unsigned int TextureFromFile(const char* path, const std::string& directory, bool gamma = false);


#endif