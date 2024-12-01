/* skandinav
 * Copyright (C) 2024 Anosh D. Ullenius
 *
 * GPL-3.0-only
 *
 * This file is part of skandinav
 *
 * skandinav is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation version 3.0.
 *
 * skandinav is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
*/
#include <stdio.h>

#define HI_BYTE 0xC3

int main(int argc, char **argv) {
    unsigned char ch = 0;
    FILE *in = NULL;
    if (argc != 2) {
        fprintf(stderr, "Usage: skandinav filename\n");
        return -1;
    }

    in = fopen(argv[1], "rb");
    if (in == NULL) {
        fprintf(stderr, "Failed to open file\n");
        return -1;
    }

    fseek(in, 0, SEEK_SET);

    while (fread(&ch, 1, 1, in) == 1) {
        const unsigned int val = ch & 0x80;
        if (val == 0) {
            putchar(ch);
        }
        else if (ch == HI_BYTE) {
            const unsigned int bytesRead = fread(&ch, 1, 1, in);
            if (bytesRead == 0) {
                fprintf(stderr, "Broken UTF-8 file\n");
                fclose(in);
                return -1;
            }
            switch (ch) {
                case 0xA5: /* å */
                case 0xA4: /* ä */
                case 0xB6: /* ö */
                case 0x85: /* Å */
                case 0x84: /* Ä */
                case 0x96: /* Ö */
                case 0x86: /* Æ */
                case 0x98: /* Ø */
                case 0xA6: /* æ */
                case 0xB8: /* ø */
                putchar(HI_BYTE);
                putchar(ch);
                break;
            }
        }
    }
    fclose(in);

    return 0;

}
