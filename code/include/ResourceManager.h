#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <map>
#include <string>
#include "mesh.h"

class ResourceManager {
public:
    // 删除复制构造函数和赋值操作符，确保只有一个实例
    ResourceManager(const ResourceManager&) = delete;
    ResourceManager& operator=(const ResourceManager&) = delete;

    // 提供一个全局访问点
    static ResourceManager& GetInstance() {
        static ResourceManager instance; // Guaranteed to be destroyed and instantiated on first use
        return instance;
    }

    unsigned int LoadTexture(const char *path);
    // 其他资源加载函数...

    // 存储资源的容器
    std::map<std::string, Texture> Textures;
    std::map<std::string, Shader> Shaders;
    std::map<std::string, Mesh> Meshes;

    // 创建纹理的函数
    Texture& LoadTexture(std::string file, std::string name);
    Texture& GetTexture(std::string name);

    // 创建着色器的函数
    Shader& LoadShader(std::string vShaderFile, std::string fShaderFile, std::string name);
    Shader& GetShader(std::string name);

    // 加载模型的函数
    Mesh& LoadMesh(std::string file, std::string name);
    Mesh& GetMesh(std::string name);

    // 绑定VAO和VBO等的函数
    void SetupMesh(Mesh& mesh);

    // 清除所有资源
    void Clear();


private:
    // 私有的构造函数，确保单例
    ResourceManager() {}
    ~ResourceManager() {}

    // 加载和编译着色器的辅助函数
    Shader loadShaderFromFile(std::string vShaderFile, std::string fShaderFile);

    // 加载纹理的辅助函数
    Texture loadTextureFromFile(std::string file);

    // 加载模型的辅助函数
    // Mesh loadMeshFromFile(std::string file);

    // 存储资源的容器
    std::map<std::string, unsigned int> textures; // 纹理资源映射
    // 可能还有其他资源类型，如模型、声音等
};

#endif // RESOURCEMANAGER_H
