from micropython import const
import framebuf
from machine import Pin, I2C

# register definitions
SET_CONTRAST = const(0x81)
SET_ENTIRE_ON = const(0xA4)
SET_NORM_INV = const(0xA6)
SET_DISP = const(0xAE)
SET_MEM_ADDR = const(0x20)
SET_COL_ADDR = const(0x21)
SET_PAGE_ADDR = const(0x22)
SET_DISP_START_LINE = const(0x40)
SET_SEG_REMAP = const(0xA0)
SET_MUX_RATIO = const(0xA8)
SET_COM_OUT_DIR = const(0xC0)
SET_DISP_OFFSET = const(0xD3)
SET_COM_PIN_CFG = const(0xDA)
SET_DISP_CLK_DIV = const(0xD5)
SET_PRECHARGE = const(0xD9)
SET_VCOM_DESEL = const(0xDB)
SET_CHARGE_PUMP = const(0x8D)

ADDR = const(0x3D)
pages = 64 // 8

i2c = I2C(0, scl=Pin(22), sda=Pin(21), freq=100000)
buffer = bytearray(pages * 128)
fbuff = framebuf.FrameBuffer(buffer, 128, 64, framebuf.MONO_VLSB)

def write_cmd(cmd):
    i2c.writeto(ADDR, bytes([ 0x80, cmd ]))

def write_data(buf):
    write_list = [b"\x40", None]  # Co=0, D/C#=1
    write_list[1] = buf
    i2c.writevto(ADDR, write_list)

def show():
    write_cmd(SET_COL_ADDR)
    write_cmd(0)
    write_cmd(128 - 1)
    write_cmd(SET_PAGE_ADDR)
    write_cmd(0)
    write_cmd(pages - 1)
    write_data(buffer)

def poweroff():
    write_cmd(SET_DISP | 0x00)

def poweron():
    write_cmd(SET_DISP | 0x01)

def contrast(contrast):
    write_cmd(SET_CONTRAST)
    write_cmd(contrast)

def invert(invert):
    write_cmd(SET_NORM_INV | (invert & 1))

def fill(c):
    fbuff.fill(c)

def pixel(x, y, c):
    fbuff.pixel(x, y, c)

def scroll(dx, dy):
    fbuff.scroll(dx, dy)

def text(string, x, y, c=1):
    fbuff.text(string, x, y, c)

def hline(x, y, w, c):
    fbuff.hline(x, y, w, c)

def vline(x, y, h, c):
    fbuff.vline(x, y, h, c)

def line(x1, y1, x2, y2, c):
    fbuff.line(x1, y1, x2, y2, c)

def rect(x, y, w, h, c):
    fbuff.rect(x, y, w, h, c)

def fill_rect(x, y, w, h, c):
    fbuff.fill_rect(x, y, w, h, c)

def blit(fbuf, x, y):
    fbuff.blit(fbuf, x, y)

def image(imageData, x, y):
    buffer = bytearray(imageData[2:])
    fbuff.blit(framebuf.FrameBuffer(buffer, int(imageData[0]), int(imageData[1]), framebuf.MONO_HLSB), x, y)
    buffer = None

setupCMD = (
    SET_DISP | 0x00,  # off
    # address setting
    SET_MEM_ADDR, 0x00,  # horizontal
    # resolution and layout
    SET_DISP_START_LINE | 0x00,
    SET_SEG_REMAP | 0x01,  # column addr 127 mapped to SEG0
    SET_MUX_RATIO, 64 - 1,
    SET_COM_OUT_DIR | 0x08,  # scan from COM[N] to COM0
    SET_DISP_OFFSET, 0x00,
    SET_COM_PIN_CFG, 0x12,
    # timing and driving scheme
    SET_DISP_CLK_DIV, 0x80,
    SET_PRECHARGE, 0xF1,
    SET_VCOM_DESEL, 0x30,  # 0.83*Vcc
    # display
    SET_CONTRAST, 0xFF,  # maximum
    SET_ENTIRE_ON,  # output follows RAM contents
    SET_NORM_INV,  # not inverted
    SET_CHARGE_PUMP, 0x14, # charge pump
    SET_DISP | 0x01, # on
)

for cmd in setupCMD:  
    write_cmd(cmd)
fill(0)
show()
