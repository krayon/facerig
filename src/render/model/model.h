#ifndef FACERIG_MODEL_H
#define FACERIG_MODEL_H

#include <string>
#include <vector>
#include <array>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include "stb_image.h"

#include "mesh.h"
#include "../shader/shader.h"

// enum class TextureType : char[10] { diffuse = "diffuse" };

struct Texture {
    unsigned int id;
    std::string type;
    std::string path;
};


class Model {
public:
    Model() {};
    explicit Model(std::string & path)  {
        load_model(path);
    }

    const std::vector<Mesh> &get_meshes() const;
    const std::vector<Texture> &get_textures() const;

private:
    void load_model(std::string path);

    Mesh process_mesh(aiMesh *mesh, const aiScene *scene);
    std::vector<Vertex> load_vertices(const aiMesh *mesh);
    std::vector<unsigned int> load_indices(const aiMesh *mesh);

    bool mesh_has_material(const aiMesh *mesh);
    std::vector<unsigned int> load_material(const aiMesh *mesh, const aiScene *scene);
    unsigned int load_texture(aiString image_path, aiTextureType type);

    std::string directory;
    std::vector<Mesh> meshes;
    std::vector<Texture> textures;
};


#endif //FACERIG_MODEL_H
