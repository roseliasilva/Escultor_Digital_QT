#ifndef VOXEL_H
#define VOXEL_H

/**
 * @file voxel.h
 * @authors Quelita Míriam e Rosélia Nascimento
 * @since 07/2022
 * @brief Classe Voxel é um struct que comporta as propriedades necessárias para permitir armazenar três tipos de informações: a cor do voxel, sua transparência e se ele deverá ser incluído ou não no modelo digital que representa a escultura.
 */

struct Voxel {
  float r,g,b;
  float a;
  bool isOn = false;
};

#endif // VOXEL_H
