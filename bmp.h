// windows bitmap

#ifndef _BMP_
#define _BMP_

#include <stdio.h>

#include "cdefs.h"

// ��� �������-����������� ������.
typedef void (*bmp_error_t)(const char* msg);

// ��������� ����������� ������.
// �� ��������� ���������� ������ ������� ��������� �� stdout
// � ��������� ���������� ���������.
void setup_bmp_error(bmp_error_t);

// ������������ ���� ����� �� �������� ������� BMP
// ���� ����������� � ���� ���� ��������� � �������� ����� RGB.
// ������ �������� ���������� ������������ ������������ ���������.

class bmp_rgb {
public:
    // �������������� �� ���������
    // ��� ����� ������������� ���������� ������ �����
    bmp_rgb()
        : _red(0), _green(0), _blue(0) {}

    // ������������� ���� ��������� ����������
    bmp_rgb(uchar r, uchar g, uchar b)
        : _red(r), _green(g), _blue(b) {}

    // ������������� ��������� ���� �������� ���������
    void set(uchar r, uchar g, uchar b) {
        _red = r; _green = g; _blue = b;
    }

    // ��������� �������� �������� ���������
    uchar red()   const { return _red; }
    uchar green() const { return _green; }
    uchar blue()  const { return _blue; }

    // ��������� �������� �������� ���������
    // ������� ���������� ������ �� ����������,
    // �������� �������� �������� ����������

    void set_red(uchar r) { _red = r; }
    void set_green(uchar g) { _green = g; }
    void set_blue(uchar b) { _blue = b; }

    // �������� ������������� �������� �������
    uchar gray() const;

private:
    uchar _red, _green, _blue;
};

// ������������ ����� ������� � ����� BMP

const int MAXPALSIZE = 256;

// �������, �������� � ������ ����� ������� BMP
// ������� ����������� � ������ ������������ ��������
// (true color, 24 ���� �� ������).
// ���������� ������������� ������� ��������� � ���,
// ��� ��� �������� � ����� ������� BMP.
// ��������� �������� ����������� �������������� � ������ ���������.

class bmp_pal {
public:
    // ��������� ����� ������� � �������� ��������� �������
    // size - ������ �������
    // ��� size == 0 ��������� ������ �������,
    // ��������������� ������������� �����������.
    bmp_pal(int size = 0);

    // ��������� ������� �� ����� ������� BMP
    // fname - ��� �����
    // sz - ������ �������� �������
    bmp_pal(const char* fname, int sz);

    // ��������� ������� �������
    // ���������� ������ ������� � �������
    int len() const { return _len; }

    // �������� ������� ������� � �������� ��������
    bmp_rgb get(int idx) const;

    // ��������� �������� �������� ������� � �������� ��������
    void put(int idx, bmp_rgb rgb);

    // ������ ������� � ���� BMP
    // file - �������� ����, � ������� ������������ ������
    void save(FILE* file) { write(file); }

private:
    int _len;
    uint32 _pal[MAXPALSIZE];

    // ������ ������� �������� ����� �� ����� �� ��������� ��������
    // ��������� ������ ������������ �������
    // ������������ ������ �������� ������ bitmap
    void read(FILE* file, int size);
    void write(FILE* file);
};

// ����� ��������� ������ � ������ ��������� bmp-�����

class bmp_header {
public:
    // ��������� ��������� �� �����.
    // fname - ��� �����, �� �������� ������������ ������
    bmp_header(const char* fname);

    // �������� ��������� �� ����������
    // height - ������ �����������
    // width - ������ �����������
    // palsize - ������ �������
    bmp_header(int height, int width, int palsize);

    // ��������� ��������� � �������� ����
    void save(FILE* file) { write(file); }

    // �������� ������ ������� � �������
    int palsize() const { return _palsize; }

    // �������� ������ ����������� � ��������
    int width()   const { return _width; }

    // �������� ������ ����������� � ��������
    int height()  const { return _height; }

    // �������� ������� ����� � ����� �� ������
    int bitsperpixel() const { return _bitsperpixel; }

    // �������� ������ ����������� � ������
    int bytesperline() const { return _bpl; }

private:
    int _palsize;
    int _width, _height;
    int _bitsperpixel;
    int _bpl;

    void write16(FILE* file, int);
    void write32(FILE* file, int);
    int read16(FILE* file, int ofs);
    int read32(FILE* file, int ofs);

    void write(FILE* file);
    void read(FILE* file);

    int width2bpl(int width);
    int palsize2bpp(int);
};

// ����������� � ������� BMP
// ���������� �������� � 1,4,8,24,32 ������ �� �����.
// ��� ������ ����������� �� ����� ��������� ��������� ������ �������� �������.
// ��� �������� ����������� ������ ���� ������ ������ �������
// � ��� ���� �� ������� ������� ������������ ������� ����� (��� �� �����)
// �� ���������� �������: 0->24, 2->1, 16->4, 256->8.
// Y-���������� ������������� ��� �������� ����.

class bitmap {
public:
    // ������ ����������� �� �����
    bitmap(const char* fname);

    // �������� ����������� � ��������� �����������
    // height - ������ ������������ �����������
    // width - ������ ������������ �����������
    // pal - ������� ������������ �����������
    bitmap(int height, int width, const bmp_pal& pal);

    ~bitmap();

    // ���������� ����������� � �����
    void save(const char* name);

    // ��������� ������ ����������� � ��������
    int width() const { return _hdr.width(); }

    // ��������� ������ ����������� � ��������
    int height() const { return _hdr.height(); }

    // ��������� ������� ����� � ����� �� ����� (1,4,8,24)
    int bpp() const { return _hdr.bitsperpixel(); }

    // �������� ������ �� ������� �����������
    bmp_pal& get_pal() { return _pal; }

    // �������� ���� ����� � ��������� ������������
    bmp_rgb get(int y, int x) const;

    // ���������� ���� ����� � ��������, �������� ��� �������� ���� (RGB).
    // ��������� ������ ��� ����������� � �������� ����� 24 ���� �� �����.
    void put(int y, int x, bmp_rgb rgb);

    // ���������� ���� ���� ����� � ��������, �������� ��� �������� ���� (RGB).
    // ��������� ������ ��� ����������� � �������� ����� 24 ���� �� �����.
    void fill(bmp_rgb rgb);

    // ���������� ���� ����� � ��������, �������� �������� ����� � ������� �������.
    // ��������� ������ ��� ����������� � �������� ����� 1,4,8 ��� �� �����.
    // cidx - ������ ����� � ������� �������.
    void put(int y, int x, int cidx);

    // ���������� ���� ���� ����� � ��������, �������� �������� ����� � ������� �������.
    // ��������� ������ ��� ����������� � �������� ����� 1,4,8 ��� �� �����.
    // cidx - ������ ����� � ������� �������.
    void fill(int cidx);

private:
    bmp_header _hdr;
    bmp_pal _pal;
    uchar* _image;

    uchar read_byte(FILE*);
    void write_byte(FILE*, uchar);

    void read(FILE*);
    void write(FILE*);

    uchar getcolidx(int lidx, int x) const;
    void  setcolidx(int lidx, int x, int cidx);

    // ��������� ���������� ������
    bitmap(const bitmap&);
    bitmap& operator=(const bitmap&);
};

#endif // _BMP_