# Arduino
Существует много способов, чтобы получить данные от Raspberry Pi 1 в Arduino.
В даннм репозитории используется два варианта по Serial и с спользованием протокола i2c.

## Serial
Подключаем Arduino по USB в Raspberry Pi.
Загружаем код `read_data_by_serial.ino` В Arduino. Теперь Ардуино будет получать данные в виде строки по Serial.

На Raspberry Pi открываем терминал и выполняем 

`lsusb`

Смотрим какие устройства у нас устройства подключены. 
Ищем что-то на подобии `dev/ttyUSB0` (может быть `dev/ttyUSB1`)
После запоминаем и открываем python файл и выполняем следующий код:
```python
inport serial 
import RPI.GPIO as GPIO

ser = serial.Serial ("dev/ttyUSB0", 9600)
ser.boudrate = 9600

ser.write(b'hello world')
```

Данный код отправит по Serial` hello world` на Arduino.

Получая определенные значения по Serial, Arduino будет отправлять на пин сигнал.

## i2c
Подключить Arduino к Rasberry Pi как показано на картинке ниже

[![](https://www.rootfront.com/image/photo/8105081.png)](https://www.rootfront.com/image/photo/8105081.png)
>Подключение по i2c между собой  Arduino и Rasberry Pi 

Загружаем `read_byte_by_i2c.ino` на Arduino.

Открываем терминал на Rasberry Pi и выполняем 

```
sudo apt-get update
sudo apt-get install i2c-tools (необязательно, но удобно просматривать подключенные устройства и всячески работать с шиной I2C в консоли)
sudo apt-get install python-smbus`
```
Так мы установили i2c

Сначала в raspiconfig мы выставляем разрешение на работу I2C порта. Находим в главном меню настройки Preference — Interfeis — I2C — Enable.

Перезагружаемся:
`sudo reboot`

После перезагрузки проверяем, есть наше устройство?:
`ls /dev | grep i2c`
Если в ответ на эту команду мы получили:
```
i2c-0
i2c-1
```

Теперь проверяем соединение:

`sudo i2cdetect -y 1`

В ответ должна выскочить картинка в консоли. Где везде `--` кроме адреса куда подключилось Arduino. 
По плану будет число `04` в первой строке в тобце под номером четыре.

Готовим python файл

```python
from smbus import SMBus

addr = 0x04 #bus addres
bus = SMBus(1) #indicates /dev/ic2-1

bus.write_byte(addr, 0x1)
```

Так мы отправили байт(`0х1`) по i2c на Arduino.  По загруженному файлу, ардуино должна подать на 13 пин сигнал. Если отправить `0х0` то  Arduino перестанет подавать напряжение на 13 пин. 