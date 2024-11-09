# Cub3D

Cub3D projesine hoş geldiniz! Bu proje, 42 okullarındaki eğitim sürecimizin bir parçası olarak [Ertuğrul Köse](https://github.com/e-kose) ile birlikte geliştirildi. Cub3D, 2D haritaları etkileyici bir 3D deneyime dönüştüren, ışın döküm (ray-casting) tekniği üzerine kurulmuş bir grafik uygulamasıdır. Amacımız, basit bir 2D labirent haritasını, oyuncunun gerçek zamanlı olarak keşfedebileceği sürükleyici bir 3D ortama dönüştürmektir.

Bu proje, grafik programlama, kullanıcı etkileşimleri ve performans optimizasyonu konularında derinlemesine bir anlayış kazandırmayı hedefledi. Cub3D, farklı yönlere sahip dokulu duvarlar, dinamik ışıklandırma efektleri ve sezgisel oyuncu kontrolleri ile klasik bir "Wolfenstein 3D" tarzı oynanış sunar. Oyuncular, WASD ve ok tuşlarıyla ortamda serbestçe gezinebilir, gizemli labirenti keşfederken hedeflerine ulaşmaya çalışabilirler.

## Game View  
[![Game View](https://github.com/menasy/cub3d/blob/main/GameView/cub3d_GameView.png)](https://github.com/menasy/cub3d/blob/main/GameView/cub3d_demo.mov)

_Click the image above to download the demo video!_

## Installation
```bash
cd Desktop
git clone git@github.com:MeNasy/cub3d.git cub3d
cd cub3d
```
For Linux install X11
```bash
sudo apt install libx11-dev libxext-dev libxi-dev libxrandr-dev libxpm-dev libxmu-dev libxi-dev libxcursor-dev libxt-dev libbsd-dev libjpeg-dev libpng-dev libtiff-dev libgif-dev libopenexr-dev libmpc-dev libgmp-dev libmpfr-dev libgomp1 libgomp-plugin-nvptx libgomp1-plugin-nvptx libatomic1 libquadmath0 libpgm-dev libssl-dev
```
## Usage
To compile the program, run:
```bash
make
```
To run the program, use one of the following commands:
```bash
./cub3d map/kvp.ber
```

## Grafik Kütüphanesi
Bu projede pencere grafik yönetimi için temel bir grafik kütüphanesi olan **MLX** kütüphanesini kullandık. MLX, bize 3B ortamı oluşturmak ve işlemek, kullanıcı girdisini yönetmek ve grafik öğelerini etkili bir şekilde işlemek için gerekli araçları ve işlevleri sağladı.

## Temel Özellikler

### Işın Döküm Sihri
Projemiz, 2B haritayı 3B harikalar diyarına dönüştürmek için ışın dökümünün gücünden yararlanıyor. Işınları ustaca manipüle ederek, bir zamanlar düz bir yüzey olan şeye derinlik ve boyut getiriyoruz. Bu teknik, gerçek zamanlı olarak 3B ortamların illüzyonunu yaratmamızı sağlıyor.

### Dokulu Duvarlar
Duvarlara dokular ekleyerek projemizi bir adım öteye taşıyoruz. Her ana yön (kuzey, güney, doğu ve batı) kendine özgü dokusuyla süslenerek sürükleyici deneyimi artırıyor. Dokulardaki çeşitlilik, sanal dünyamıza gerçekçilik ve derinlik katıyor.

### Oyuncu Kontrolleri
Oyuncular sezgisel kontrollerle 3D ortamı keşfedebilirler:
- **İleri** hareket için `W`
- **Geri** hareket için `S`
- **Sola** hareket için `A`
- **Sağa** hareket için `D`
- **Bakış açısını değiştirmek** için sol ve sağ ok tuşlarını kullanın.

Bu kontroller, keşfi kolaylaştıran akıcı ve ilgi çekici bir kullanıcı deneyimi sunar.

### Hata İşleme
Sağlam hata işlemeyi sağlamak için özen gösterdik. Projemiz, geçersiz bir haritadan kaynaklanabilecek çeşitli hata senaryolarını zarif bir şekilde işleyebilir. İster kapatılmamış bir sınır ister eksik öğeler olsun, her şeyi hallettik. Kullanıcılar, istikrarlı ve güvenilir bir deneyim bekleyebilir.


