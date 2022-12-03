<!--
 * @Author: rx-ted
 * @Date: 2022-11-27 15:09:42
 * @LastEditors: rx-ted
 * @LastEditTime: 2022-12-03 21:30:09
-->
# 371-e-paper

## pinout define

| 3.71" e-paper | wemos-D1 |  uno  |
| :-----------: | :------: | :---: |
|     busy      |    D2    |   4   |
|      res      |    D4    |   2   |
|      dc       |    D3    |   0   |
|      cs       |    D8    |  15   |
|     sclk      |    D5    |  14   |
|      sdi      |    D7    |  13   |

Arduino UNO ： except SPI pinout(cs/sclk,sdi), other can modify pinout.(busy/res/dc). Only not repeat pinout of definition.

BUSY -> D2, RST -> D4, DC -> D3, CS -> D8, CLK -> D5, DIN -> D7, GND -> GND, 3.3V -> 3.3V
