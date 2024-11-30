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

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: skandinav filename\n");
        return -1;
    }

    FILE *in = fopen(argv[1], "rb");
    if (in == NULL) {
        fprintf(stderr, "Failed to open file\n");
        return -1;
    }

    fseek(in, 0, SEEK_SET);

    unsigned char ch = 0;
    unsigned char ch2 = 0;
    while (fread(&ch, 1, 1, in) == 1) {
        const unsigned int val = ch & 0x80;
        if (val == 0) {
            putchar(ch);
        }
        else if (ch == 0xC3) {
            const unsigned int bytesRead = fread(&ch2, 1, 1, in);
            if (bytesRead == 0) {
                fprintf(stderr, "Broken UTF-8 file\n");
                fclose(in);
                return -1;
            }
            switch (ch2) {
                case 0xA5: // å
                case 0xA4: // ä
                case 0xB6: // ö
                case 0x85: // Å
                case 0x84: // Ä
                case 0x96: // Ö
                putchar(ch);
                putchar(ch2);
                break;
            }
        }
    }
    fclose(in);

    return 0;

}
