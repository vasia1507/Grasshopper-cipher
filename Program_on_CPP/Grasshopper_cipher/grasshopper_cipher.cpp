#include "grasshopper_cipher.h"

std::vector<unsigned char> Pi = {
    0xFC, 0xEE, 0xDD, 0x11, 0xCF, 0x6E, 0x31, 0x16, 0xFB, 0xC4, 0xFA, 0xDA,
    0x23, 0xC5, 0x04, 0x4D, 0xE9, 0x77, 0xF0, 0xDB, 0x93, 0x2E, 0x99, 0xBA,
    0x17, 0x36, 0xF1, 0xBB, 0x14, 0xCD, 0x5F, 0xC1, 0xF9, 0x18, 0x65, 0x5A,
    0xE2, 0x5C, 0xEF, 0x21, 0x81, 0x1C, 0x3C, 0x42, 0x8B, 0x01, 0x8E, 0x4F,
    0x05, 0x84, 0x02, 0xAE, 0xE3, 0x6A, 0x8F, 0xA0, 0x06, 0x0B, 0xED, 0x98,
    0x7F, 0xD4, 0xD3, 0x1F, 0xEB, 0x34, 0x2C, 0x51, 0xEA, 0xC8, 0x48, 0xAB,
    0xF2, 0x2A, 0x68, 0xA2, 0xFD, 0x3A, 0xCE, 0xCC, 0xB5, 0x70, 0x0E, 0x56,
    0x08, 0x0C, 0x76, 0x12, 0xBF, 0x72, 0x13, 0x47, 0x9C, 0xB7, 0x5D, 0x87,
    0x15, 0xA1, 0x96, 0x29, 0x10, 0x7B, 0x9A, 0xC7, 0xF3, 0x91, 0x78, 0x6F,
    0x9D, 0x9E, 0xB2, 0xB1, 0x32, 0x75, 0x19, 0x3D, 0xFF, 0x35, 0x8A, 0x7E,
    0x6D, 0x54, 0xC6, 0x80, 0xC3, 0xBD, 0x0D, 0x57, 0xDF, 0xF5, 0x24, 0xA9,
    0x3E, 0xA8, 0x43, 0xC9, 0xD7, 0x79, 0xD6, 0xF6, 0x7C, 0x22, 0xB9, 0x03,
    0xE0, 0x0F, 0xEC, 0xDE, 0x7A, 0x94, 0xB0, 0xBC, 0xDC, 0xE8, 0x28, 0x50,
    0x4E, 0x33, 0x0A, 0x4A, 0xA7, 0x97, 0x60, 0x73, 0x1E, 0x00, 0x62, 0x44,
    0x1A, 0xB8, 0x38, 0x82, 0x64, 0x9F, 0x26, 0x41, 0xAD, 0x45, 0x46, 0x92,
    0x27, 0x5E, 0x55, 0x2F, 0x8C, 0xA3, 0xA5, 0x7D, 0x69, 0xD5, 0x95, 0x3B,
    0x07, 0x58, 0xB3, 0x40, 0x86, 0xAC, 0x1D, 0xF7, 0x30, 0x37, 0x6B, 0xE4,
    0x88, 0xD9, 0xE7, 0x89, 0xE1, 0x1B, 0x83, 0x49, 0x4C, 0x3F, 0xF8, 0xFE,
    0x8D, 0x53, 0xAA, 0x90, 0xCA, 0xD8, 0x85, 0x61, 0x20, 0x71, 0x67, 0xA4,
    0x2D, 0x2B, 0x09, 0x5B, 0xCB, 0x9B, 0x25, 0xD0, 0xBE, 0xE5, 0x6C, 0x52,
    0x59, 0xA6, 0x74, 0xD2, 0xE6, 0xF4, 0xB4, 0xC0, 0xD1, 0x66, 0xAF, 0xC2,
    0x39, 0x4B, 0x63, 0xB6};
std::vector<unsigned char> reverse_Pi = {
    0xA5, 0x2D, 0x32, 0x8F, 0x0E, 0x30, 0x38, 0xC0, 0x54, 0xE6, 0x9E, 0x39,
    0x55, 0x7E, 0x52, 0x91, 0x64, 0x03, 0x57, 0x5A, 0x1C, 0x60, 0x07, 0x18,
    0x21, 0x72, 0xA8, 0xD1, 0x29, 0xC6, 0xA4, 0x3F, 0xE0, 0x27, 0x8D, 0x0C,
    0x82, 0xEA, 0xAE, 0xB4, 0x9A, 0x63, 0x49, 0xE5, 0x42, 0xE4, 0x15, 0xB7,
    0xC8, 0x06, 0x70, 0x9D, 0x41, 0x75, 0x19, 0xC9, 0xAA, 0xFC, 0x4D, 0xBF,
    0x2A, 0x73, 0x84, 0xD5, 0xC3, 0xAF, 0x2B, 0x86, 0xA7, 0xB1, 0xB2, 0x5B,
    0x46, 0xD3, 0x9F, 0xFD, 0xD4, 0x0F, 0x9C, 0x2F, 0x9B, 0x43, 0xEF, 0xD9,
    0x79, 0xB6, 0x53, 0x7F, 0xC1, 0xF0, 0x23, 0xE7, 0x25, 0x5E, 0xB5, 0x1E,
    0xA2, 0xDF, 0xA6, 0xFE, 0xAC, 0x22, 0xF9, 0xE2, 0x4A, 0xBC, 0x35, 0xCA,
    0xEE, 0x78, 0x05, 0x6B, 0x51, 0xE1, 0x59, 0xA3, 0xF2, 0x71, 0x56, 0x11,
    0x6A, 0x89, 0x94, 0x65, 0x8C, 0xBB, 0x77, 0x3C, 0x7B, 0x28, 0xAB, 0xD2,
    0x31, 0xDE, 0xC4, 0x5F, 0xCC, 0xCF, 0x76, 0x2C, 0xB8, 0xD8, 0x2E, 0x36,
    0xDB, 0x69, 0xB3, 0x14, 0x95, 0xBE, 0x62, 0xA1, 0x3B, 0x16, 0x66, 0xE9,
    0x5C, 0x6C, 0x6D, 0xAD, 0x37, 0x61, 0x4B, 0xB9, 0xE3, 0xBA, 0xF1, 0xA0,
    0x85, 0x83, 0xDA, 0x47, 0xC5, 0xB0, 0x33, 0xFA, 0x96, 0x6F, 0x6E, 0xC2,
    0xF6, 0x50, 0xFF, 0x5D, 0xA9, 0x8E, 0x17, 0x1B, 0x97, 0x7D, 0xEC, 0x58,
    0xF7, 0x1F, 0xFB, 0x7C, 0x09, 0x0D, 0x7A, 0x67, 0x45, 0x87, 0xDC, 0xE8,
    0x4F, 0x1D, 0x4E, 0x04, 0xEB, 0xF8, 0xF3, 0x3E, 0x3D, 0xBD, 0x8A, 0x88,
    0xDD, 0xCD, 0x0B, 0x13, 0x98, 0x02, 0x93, 0x80, 0x90, 0xD0, 0x24, 0x34,
    0xCB, 0xED, 0xF4, 0xCE, 0x99, 0x10, 0x44, 0x40, 0x92, 0x3A, 0x01, 0x26,
    0x12, 0x1A, 0x48, 0x68, 0xF5, 0x81, 0x8B, 0xC7, 0xD6, 0x20, 0x0A, 0x08,
    0x00, 0x4C, 0xD7, 0x74};
std::vector<int> lagua_table = {
    1,   2,   4,   8,   16,  32,  64,  128, 195, 69,  138, 215, 109, 218, 119,
    238, 31,  62,  124, 248, 51,  102, 204, 91,  182, 175, 157, 249, 49,  98,
    196, 75,  150, 239, 29,  58,  116, 232, 19,  38,  76,  152, 243, 37,  74,
    148, 235, 21,  42,  84,  168, 147, 229, 9,   18,  36,  72,  144, 227, 5,
    10,  20,  40,  80,  160, 131, 197, 73,  146, 231, 13,  26,  52,  104, 208,
    99,  198, 79,  158, 255, 61,  122, 244, 43,  86,  172, 155, 245, 41,  82,
    164, 139, 213, 105, 210, 103, 206, 95,  190, 191, 189, 185, 177, 161, 129,
    193, 65,  130, 199, 77,  154, 247, 45,  90,  180, 171, 149, 233, 17,  34,
    68,  136, 211, 101, 202, 87,  174, 159, 253, 57,  114, 228, 11,  22,  44,
    88,  176, 163, 133, 201, 81,  162, 135, 205, 89,  178, 167, 141, 217, 113,
    226, 7,   14,  28,  56,  112, 224, 3,   6,   12,  24,  48,  96,  192, 67,
    134, 207, 93,  186, 183, 173, 153, 241, 33,  66,  132, 203, 85,  170, 151,
    237, 25,  50,  100, 200, 83,  166, 143, 221, 121, 242, 39,  78,  156, 251,
    53,  106, 212, 107, 214, 111, 222, 127, 254, 63,  126, 252, 59,  118, 236,
    27,  54,  108, 216, 115, 230, 15,  30,  60,  120, 240, 35,  70,  140, 219,
    117, 234, 23,  46,  92,  184, 179, 165, 137, 209, 97,  194, 71,  142, 223,
    125, 250, 55,  110, 220, 123, 246, 47,  94,  188, 187, 181, 169, 145, 225,
    1};
std::vector<int> lagua_table2 = {
    0,   1,   157, 2,   59,  158, 151, 3,   53,  60,  132, 159, 70,  152, 216,
    4,   118, 54,  38,  61,  47,  133, 227, 160, 181, 71,  210, 153, 34,  217,
    16,  5,   173, 119, 221, 55,  43,  39,  191, 62,  88,  48,  83,  134, 112,
    228, 247, 161, 28,  182, 20,  72,  195, 211, 242, 154, 129, 35,  207, 218,
    80,  17,  204, 6,   106, 174, 164, 120, 9,   222, 237, 56,  67,  44,  31,
    40,  109, 192, 77,  63,  140, 89,  185, 49,  177, 84,  125, 135, 144, 113,
    23,  229, 167, 248, 97,  162, 235, 29,  75,  183, 123, 21,  95,  73,  93,
    196, 198, 212, 12,  243, 200, 155, 149, 130, 214, 36,  225, 208, 14,  219,
    189, 81,  245, 18,  240, 205, 202, 7,   104, 107, 65,  175, 138, 165, 142,
    121, 233, 10,  91,  223, 147, 238, 187, 57,  253, 68,  51,  45,  116, 32,
    179, 41,  171, 110, 86,  193, 26,  78,  127, 64,  103, 141, 137, 90,  232,
    186, 146, 50,  252, 178, 115, 85,  170, 126, 25,  136, 102, 145, 231, 114,
    251, 24,  169, 230, 101, 168, 250, 249, 100, 98,  99,  163, 105, 236, 8,
    30,  66,  76,  108, 184, 139, 124, 176, 22,  143, 96,  166, 74,  234, 94,
    122, 197, 92,  199, 11,  213, 148, 13,  224, 244, 188, 201, 239, 156, 254,
    150, 58,  131, 52,  215, 69,  37,  117, 226, 46,  209, 180, 15,  33,  220,
    172, 190, 42,  82,  87,  246, 111, 19,  27,  241, 194, 206, 128, 203, 79,
    0};
std::vector<unsigned char> l_vec = {148, 32,  133, 16, 194, 192, 1,   251,
                                    1,   192, 194, 16, 133, 32,  148, 1};
std::vector<std::vector<unsigned char>> iter_C(32,
                                               std::vector<unsigned char>(16,
                                                                          0));
std::vector<std::vector<unsigned char>> iter_key(10,
                                                 std::vector<unsigned char>(16,
                                                                            0));

std::vector<unsigned char> GOST_Kuz_X(std::vector<unsigned char> a,
                                      std::vector<unsigned char> b) {
  std::vector<unsigned char> result(BLOCK_SIZE);
  for (int i = 0; i < BLOCK_SIZE; i++) {
    result[i] = (unsigned char)(a[i] ^ b[i]);
  }
  return result;
}

std::vector<unsigned char> GOST_Kuz_S(std::vector<unsigned char> in_data) {
  std::vector<unsigned char> result(BLOCK_SIZE);
  for (int i = 0; i < BLOCK_SIZE; i++) {
    int data = in_data[i];
    if (data < 0) data = data + 256;
    result[i] = Pi[data];
  }
  return result;
}

unsigned char GOST_Kuz_GF_mul(unsigned char a, unsigned char b) {
  if (a == 0 || b == 0) return 0;
  int stepen_a = lagua_table2[a - 1];
  int stepen_b = lagua_table2[b - 1];
  int stepen_res = (stepen_a + stepen_b) % 255;
  int result = lagua_table[stepen_res];
  return result;
}

std::vector<unsigned char> GOST_Kuz_R(std::vector<unsigned char> state) {
  unsigned char a_0 = 0;
  std::vector<unsigned char> result(BLOCK_SIZE);
  for (int i = 15; i >= 0; i--) {
    if (i != 0) {
      result[i] = state[i - 1];
    }
    a_0 ^= GOST_Kuz_GF_mul(state[i], l_vec[i]);
  }
  result[0] = a_0;
  return result;
}

std::vector<unsigned char> GOST_Kuz_L(std::vector<unsigned char> in_data) {
  std::vector<unsigned char> result(BLOCK_SIZE);
  std::vector<unsigned char> internal = in_data;
  for (int i = 0; i < 16; i++) {
    internal = GOST_Kuz_R(internal);
  }
  result = internal;
  return result;
}

std::vector<unsigned char> GOST_Kuz_reverse_S(
    std::vector<unsigned char> in_data) {
  std::vector<unsigned char> result(BLOCK_SIZE);
  for (int i = 0; i < BLOCK_SIZE; i++) {
    int data = in_data[i];
    if (data < 0) {
      data = data + 256;
    }
    result[i] = reverse_Pi[data];
  }
  return result;
}

std::vector<unsigned char> GOST_Kuz_reverse_R(
    std::vector<unsigned char> state) {
  unsigned char a_15 = 0;
  std::vector<unsigned char> result(BLOCK_SIZE, 0);
  for (int i = 0; i < 15; i++) {
    result[i] = state[i + 1];
    a_15 ^= GOST_Kuz_GF_mul(state[i + 1], l_vec[i]);
  }
  a_15 ^= GOST_Kuz_GF_mul(state[0], l_vec[15]);
  result[15] = a_15;
  return result;
}

std::vector<unsigned char> GOST_Kuz_reverse_L(
    std::vector<unsigned char> in_data) {
  std::vector<unsigned char> result(BLOCK_SIZE, 0);
  std::vector<unsigned char> internal;
  internal = in_data;
  for (int i = 0; i < 16; i++) {
    internal = GOST_Kuz_reverse_R(internal);
  }
  result = internal;
  return result;
}

void GOST_Kuz_Get_C() {
  std::vector<unsigned char> iter_num(16, 0);
  for (int i = 0; i < 32; i++) {
    iter_num[15] = i + 1;
    iter_C[i] = GOST_Kuz_L(iter_num);
  }
}

std::vector<std::vector<unsigned char>> GOST_Kuz_F(
    std::vector<unsigned char> in_key_1, std::vector<unsigned char> in_key_2,
    std::vector<unsigned char> iter_const) {
  std::vector<unsigned char> internal;
  std::vector<unsigned char> out_key_2 = in_key_1;
  internal = GOST_Kuz_X(in_key_1, iter_const);
  internal = GOST_Kuz_S(internal);
  internal = GOST_Kuz_L(internal);
  std::vector<unsigned char> out_key_1 = GOST_Kuz_X(internal, in_key_2);
  std::vector<std::vector<unsigned char>> key(2, std::vector<unsigned char>());
  key[0] = out_key_1;
  key[1] = out_key_2;
  return key;
}

void GOST_Kuz_Expand_Key(std::vector<unsigned char> key_1,
                         std::vector<unsigned char> key_2) {
  std::vector<std::vector<unsigned char>> iter12(2,
                                                 std::vector<unsigned char>());
  std::vector<std::vector<unsigned char>> iter34(2,
                                                 std::vector<unsigned char>());
  iter_key[0] = key_1;
  iter_key[1] = key_2;
  iter12[0] = key_1;
  iter12[1] = key_2;
  for (int i = 0; i < 4; i++) {
    iter34 = GOST_Kuz_F(iter12[0], iter12[1], iter_C[0 + 8 * i]);
    iter12 = GOST_Kuz_F(iter34[0], iter34[1], iter_C[1 + 8 * i]);
    iter34 = GOST_Kuz_F(iter12[0], iter12[1], iter_C[2 + 8 * i]);
    iter12 = GOST_Kuz_F(iter34[0], iter34[1], iter_C[3 + 8 * i]);
    iter34 = GOST_Kuz_F(iter12[0], iter12[1], iter_C[4 + 8 * i]);
    iter12 = GOST_Kuz_F(iter34[0], iter34[1], iter_C[5 + 8 * i]);
    iter34 = GOST_Kuz_F(iter12[0], iter12[1], iter_C[6 + 8 * i]);
    iter12 = GOST_Kuz_F(iter34[0], iter34[1], iter_C[7 + 8 * i]);
    iter_key[2 * i + 2] = iter12[0];
    iter_key[2 * i + 3] = iter12[1];
  }
}

std::vector<unsigned char> GOST_Kuz_Encript(std::vector<unsigned char> blk,
                                            std::vector<unsigned char> key_1,
                                            std::vector<unsigned char> key_2) {
  std::vector<unsigned char> result(BLOCK_SIZE);
  result = blk;
  for (int i = 0; i < 9; i++) {
    result = GOST_Kuz_X(iter_key[i], result);
    result = GOST_Kuz_S(result);
    result = GOST_Kuz_L(result);
  }
  result = GOST_Kuz_X(result, iter_key[9]);
  return result;
}

std::vector<unsigned char> GOST_Kuz_Decript(std::vector<unsigned char> blk,
                                            std::vector<unsigned char> key_1,
                                            std::vector<unsigned char> key_2) {
  std::vector<unsigned char> result(BLOCK_SIZE, 0);
  result = blk;
  for (int i = 9; i >= 1; i--) {
    result = GOST_Kuz_X(iter_key[i], result);
    result = GOST_Kuz_reverse_L(result);
    result = GOST_Kuz_reverse_S(result);
  }
  result = GOST_Kuz_X(result, iter_key[0]);
  return result;
}

void separate_key(std::string main_key, std::vector<unsigned char>& key_1,
                  std::vector<unsigned char>& key_2) {
  int tmp1 = 0, tmp2 = 0;
  for (int i = 0; i < 16; i++) {
    if (48 <= main_key[2 * i] && main_key[2 * i] <= 57)
      tmp1 = main_key[2 * i] - 48;
    if (97 <= main_key[2 * i] && main_key[2 * i] <= 102)
      tmp1 = main_key[2 * i] - 87;
    if (48 <= main_key[2 * i + 1] && main_key[2 * i + 1] <= 57)
      tmp2 = main_key[2 * i + 1] - 48;
    if (97 <= main_key[2 * i + 1] && main_key[2 * i + 1] <= 102)
      tmp2 = main_key[2 * i + 1] - 87;
    key_1[i] = (unsigned char)(tmp1 << 4 | tmp2);
    if (48 <= main_key[2 * i + 32] && main_key[2 * i + 32] <= 57)
      tmp1 = main_key[2 * i + 32] - 48;
    if (97 <= main_key[2 * i + 32] && main_key[2 * i + 32] <= 102)
      tmp1 = main_key[2 * i + 32] - 87;
    if (48 <= main_key[2 * i + 32 + 1] && main_key[2 * i + 32 + 1] <= 57)
      tmp2 = main_key[2 * i + 32 + 1] - 48;
    if (97 <= main_key[2 * i + 32 + 1] && main_key[2 * i + 32 + 1] <= 102)
      tmp2 = main_key[2 * i + 32 + 1] - 87;
    key_2[i] = (unsigned char)(tmp1 << 4 | tmp2);
  }
}

void Encript_File(std::string file_name, std::string main_key) {
  std::vector<unsigned char> key_1(16, 0);
  std::vector<unsigned char> key_2(16, 0);
  separate_key(main_key, key_1, key_2);
  GOST_Kuz_Get_C();
  GOST_Kuz_Expand_Key(key_1, key_2);
  std::vector<unsigned char> buffer(16, 0);
  std::ifstream file(file_name, std::ios::binary);
  std::ofstream out(file_name + ".crypto", std::ios::binary);
  while (1) {
    file.read(reinterpret_cast<char*>(buffer.data()), 16);
    int bytesRead = file.gcount();
    if (bytesRead == 0) break;
    buffer = GOST_Kuz_Encript(buffer, key_1, key_2);
    for (int i = 0; i < 16; i++) out << buffer[i];
    buffer = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  }
  file.close();
  out.close();
  QFile file_remove(QString::fromStdString(file_name));
  file_remove.remove();
  file_remove.close();
  QFile file_rename(QString::fromStdString(file_name + ".crypto"));
  file_rename.rename(QString::fromStdString(file_name));
  file_rename.close();
}

void Decript_File(std::string file_name, std::string main_key) {
  std::vector<unsigned char> key_1(16, 0);
  std::vector<unsigned char> key_2(16, 0);
  separate_key(main_key, key_1, key_2);
  GOST_Kuz_Get_C();
  GOST_Kuz_Expand_Key(key_1, key_2);
  std::vector<unsigned char> buffer(16, 0);
  std::ifstream file(file_name, std::ios::binary);
  std::ofstream out(file_name + ".crypto", std::ios::binary);
  while (1) {
    file.read(reinterpret_cast<char*>(buffer.data()), 16);
    int bytesRead = file.gcount();
    if (bytesRead == 0) break;
    buffer = GOST_Kuz_Decript(buffer, key_1, key_2);
    for (int i = 0; i < 16; i++) out << buffer[i];
    buffer = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  }
  file.close();
  out.close();
  QFile file_remove(QString::fromStdString(file_name));
  file_remove.remove();
  file_remove.close();
  QFile file_rename(QString::fromStdString(file_name + ".crypto"));
  file_rename.rename(QString::fromStdString(file_name));
  file_rename.close();
}

int validate(std::string main_key) {
  int result = 0;
  if (main_key.length() != 64) {
    result = 1;
  } else {
    for (int i = 0; i < main_key.length(); i++) {
      if (!(48 <= main_key[i] && main_key[i] <= 57 ||
            97 <= main_key[i] && main_key[i] <= 102)) {
        result = 2;
        break;
      }
    }
  }
  return result;
}
