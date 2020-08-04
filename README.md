# PNG Pixel Number
Um script simples para calcular a quantidade de pixels em arquivos png.

### Instalação
Para instalar esse script, basta clonar o repositório com o parâmetro --recurse-submodules, sendo assim

```
git clone --recurse-submodules https://github.com/Henric234/PNGPixelNumber.git
```
Após terminada a instalação, basta acessar a pasta  src dentro da pasta PNGPixelNumber.

```
cd PNGPixelNumber/src/
```
Então, basta compilar com o makefile

```
make
```
E finalmente executar

```
./output
```
### Sobre
Esse script é compilado com g++ (GNU Compiler Collection), e feito em C++17, fazendo uso de sua biblioteca Filesystem.
Além disso, para obter os dados sobre os arquivos, é utilizada a biblioteca [LodePNG](https://lodev.org/lodepng/).
O código, em si, consiste apenas na função main, que realiza todas as operações. Optei por fazer assim pois, a priori, essa é a única função desse script.
