#include <SDL.h>
#include <iostream>
#include <string>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 800;

class Titik {
public:
    std::string nama;
    int x;
    int y;
    Titik(std::string nama, int x, int y) : nama(nama), x(x), y(y) {}
};

class Peta {
private:
    int jumlah_titik;
    Titik** titik_list;
    int** adjacency_matrix;

public:
    Peta(int jumlah_titik) {
        this->jumlah_titik = jumlah_titik;
        this->inisialisasiTitikList(jumlah_titik);
        this->inisialisasiAdjMatrix(jumlah_titik);
    }

    ~Peta() {
        for (int i = 0; i < jumlah_titik; i++) {
            delete titik_list[i];
        }
        delete[] titik_list;
        for (int i = 0; i < jumlah_titik; i++) {
            delete[] adjacency_matrix[i];
        }
        delete[] adjacency_matrix;
    }

    int getJumlahTitik() const {
        return jumlah_titik;
    }

    Titik getTitik(int index) const {
        return *titik_list[index];
    }

    int getAdjMatrix(int row, int col) const {
        return adjacency_matrix[row][col];
    }

    void inisialisasiTitikList(int jumlah_titik) {
        titik_list = new Titik*[jumlah_titik];
        // Inisialisasi titik sesuai dengan data yang Anda miliki
        // Contoh inisialisasi titik:
        titik_list[0] = new Titik("Rumah kos", 1116, 1406);
        titik_list[1] = new Titik("pertigaan_blokT", 1002, 1402);
        titik_list[2] = new Titik("gapura_perumdosT", 1002, 1294);
        titik_list[3] = new Titik("bunderan_CCWS", 364, 1284);
        titik_list[4] = new Titik("belokan_perumdosT", 1120, 1286);
        titik_list[5] = new Titik("belokan_perumdosU", 1160, 906);
        titik_list[6] = new Titik("belokan_tekpal", 1006, 874);
        titik_list[7] = new Titik("bunderan_daspro", 1098,490);
        titik_list[8] = new Titik("gerbang_its_utara", 748, 44);
        titik_list[9] = new Titik("bunderan_manarul", 382, 922);
        titik_list[10] = new Titik("belokan_manarul", 206, 870);
        titik_list[11] = new Titik("bunderan_lapanganalumni", 272, 612);
        titik_list[12] = new Titik("gerbang_barat", 108, 312);
        titik_list[13] = new Titik("gerbang_selatan", 28, 1712);
    }

    void inisialisasiAdjMatrix(int jumlah_titik) {
        adjacency_matrix = new int* [jumlah_titik];
        for (int i = 0; i < jumlah_titik; i++) {
            adjacency_matrix[i] = new int[jumlah_titik];
            for (int j = 0; j < jumlah_titik; j++) {
                adjacency_matrix[i][j] = 0;
            }
        }
    }

    void tambahLintasan(int titik_awal, int titik_tujuan) {
        adjacency_matrix[titik_awal][titik_tujuan] = 1;
        adjacency_matrix[titik_tujuan][titik_awal] = 1;
    }
};

void drawMap(SDL_Renderer* renderer, const Peta& peta) {
    // Scalling ukuran graph terhadap ukuran window
    double scaleX = SCREEN_WIDTH / 2300.0;
    double scaleY = SCREEN_HEIGHT / 1800.0;

    // Pengaturan radius lingkaran
    int circleRadius = 10;

    for (int i = 0; i < peta.getJumlahTitik(); i++) {
        int x1 = peta.getTitik(i).x * scaleX;
        int y1 = peta.getTitik(i).y * scaleY;

        // Menggambar lingkaran di sekitar titik
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); // Warna biru
        for (int dx = -circleRadius; dx <= circleRadius; dx++) {
            for (int dy = -circleRadius; dy <= circleRadius; dy++) {
                if (dx * dx + dy * dy <= circleRadius * circleRadius) {
                    SDL_RenderDrawPoint(renderer, x1 + dx, y1 + dy);
                }
            }
        }

        for (int j = 0; j < peta.getJumlahTitik(); j++) {
            if (peta.getAdjMatrix(i, j) == 1) {
                int x2 = peta.getTitik(j).x * scaleX;
                int y2 = peta.getTitik(j).y * scaleY;

                // Menggambar garis
                SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Warna merah
                SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
            }
        }
    }
}

int main() {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("Peta Rumah (Kos)", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    int jumlah_titik = 14;
    Peta petaKu(jumlah_titik);

    // Menambahkan lintasan seperti yang Anda lakukan di dalam main Anda
    petaKu.tambahLintasan(0, 1);
    petaKu.tambahLintasan(1, 0);
    petaKu.tambahLintasan(1, 2);
    petaKu.tambahLintasan(2, 1);
    petaKu.tambahLintasan(2, 3);
    petaKu.tambahLintasan(2, 4);
    petaKu.tambahLintasan(3, 2);
    petaKu.tambahLintasan(3, 9);
    petaKu.tambahLintasan(3, 13);
    petaKu.tambahLintasan(4, 2);
    petaKu.tambahLintasan(4, 5);
    petaKu.tambahLintasan(5, 4);
    petaKu.tambahLintasan(5, 6);
    petaKu.tambahLintasan(6, 5);
    petaKu.tambahLintasan(6, 7);
    petaKu.tambahLintasan(7, 6);
    petaKu.tambahLintasan(7, 8);
    petaKu.tambahLintasan(8, 7);
    petaKu.tambahLintasan(8, 12);
    petaKu.tambahLintasan(9, 3);
    petaKu.tambahLintasan(9, 10);
    petaKu.tambahLintasan(10, 9);
    petaKu.tambahLintasan(10, 11);
    petaKu.tambahLintasan(11, 10);
    petaKu.tambahLintasan(11, 12);
    petaKu.tambahLintasan(12, 11);
    petaKu.tambahLintasan(12, 8);
    petaKu.tambahLintasan(13, 3);

    bool quit = false;
    SDL_Event e;

    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        drawMap(renderer, petaKu);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
