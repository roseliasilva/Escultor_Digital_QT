#ifndef SCULPTOR_H
#define SCULPTOR_H

/**
 * @file sculptor.h
 * @authors Quelita Míriam e Rosélia Nascimento
 * @since 07/2022
 * @brief Classe Sculptor
 */

#include "voxel.h"

/*** A primeira etapa do projeto consiste em conceber uma classe em C++ que permita realizar operações em uma matriz tridimensional alocada dinamicamente. Os elementos dessa matriz guardam propriedades da escultura e são denominados Voxels (volume elements).
* Tal matriz possue dimensões de comprimento, altura e largura especificadas pelo usuário, onde os índices dos elementos nessa matriz coresponderiam às posições dos voxels no espaço discreto. Além disso há instancias de cores e transparência do voxel.
* A Classe Sculptor instancia todos os objetos e métodos que serão utilizados para a escultura do desenho, que por sua vez são inicializadas por um Contrutor e liberadas por um destrutor.
*/

class Sculptor {
protected:
  Voxel ***v;
  int nx,ny,nz;
  float r,g,b,a;
  float cor;

public:
  Sculptor(int _nx, int _ny, int _nz);
  ~Sculptor();

  /**
  * O método Red() recebe a cor vermelha do sistema de cor RGB e salva em uma instância da classe.
  */
  void Red(float r_);
  /**
  * O método Green() recebe a cor verde do sistema de cor RGB e salva em uma instância da classe.
  */
  void Green(float g_);
  /**
  * O método Blue() recebe a cor azul do sistema de cor RGB e salva em uma instância da classe.
  */
  void Blue(float b_);
  /**
  * O método Alpha() recebe a transparência para o voxel e salva em uma instância da classe.
  */
  void Alpha(float a_);

  void setColor(float r, float g, float b, float a);

/**
* O método putVoxel() ativa o voxel na posição (x,y,z) da matriz recebidas pelo usuário e atribui ao mesmo a cor atual de desenho.
*/
  void putVoxel(int x, int y, int z);
/**
* O método cutVoxel() desativa o voxel na posição (x,y,z) recebida pelo usuário.
*/
  void cutVoxel(int x, int y, int z);
/**
* O método putBox() ativa todos os voxels no intervalo x∈[x0,x1], y∈[y0,y1], z∈[z0,z1] e atribui aos mesmos a cor atual de desenho.
*/
  void putBox(int x0, int x1, int y0, int y1, int z0, int z1);
/**
* O método cutBox() desativa todos os voxels no intervalo x∈[x0,x1], y∈[y0,y1], z∈[z0,z1] e atribui aos mesmos a cor atual de desenho.
*/
  void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
/**
*O método putSphere() recebe do usuário a posição (x,y,z) e seu raio, ativando assim todos os voxels que satisfazem à equação da esfera e atribui aos mesmos a cor atual de desenho (r,g,b,a).
*/
  void putSphere(int xcenter, int ycenter, int zcenter, int radius);
/**
* O método cutSphere() recebe do usuário a posição (x,y,z) e seu raio para desativar todos os voxels que satisfazem à equação da esfera.
*/
  void cutSphere(int xcenter, int ycenter, int zcenter, int radius);
/**
* O método putEllipsoid() recebe do usuário a posição (x,y,z) e seus raios para ativar todos os voxels que satisfazem à equação do elipsóide e atribui aos mesmos a cor atual de desenho.
*/
  void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
/**
* O método cutEllipsoid() recebe do usuário a posição (x,y,z) e seus raios para desativar todos os voxels que satisfazem à equação do elipsóide.
*/
  void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
/**
* O método writeOFF() grava as descrições da escultura até então elaboradas pelos métodos acima no formato OFF no arquivo filename enviado.
*/
  void writeOFF(const char* filename);
};

#endif // SCULPTOR_H
