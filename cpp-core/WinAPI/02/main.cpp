#include <windows.h>

// Прототип функции обработки сообщений с пользовательским названием:
LRESULT CALLBACK WindowProcess(HWND, UINT, WPARAM, LPARAM);

TCHAR mainMessage[] = "Hello World";        // строка с сообщением

// Управляющая функция:
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCommandLine, int nCommandShow) {
    TCHAR szClassName[] = "Entity";        // строка с именем класса
    HWND hMainWindow;                            // создание дескриптора будущего окошка
    MSG message;                                // создание экземпляра структуры MSG для обработки сообщений
    WNDCLASSEX windowClass;                            // создание экземпляра класса WNDCLASSEX (класса окна)

    // инициализация полей windowClass
    windowClass.cbSize = sizeof(windowClass);                                    // размер структуры (в байтах)
    windowClass.style = CS_HREDRAW | CS_VREDRAW;                        // стиль класса окна
    windowClass.lpfnWndProc = WindowProcess;                                // указатель на имя пользовательской функции
    windowClass.cbWndExtra = NULL;                                    // число освобождаемых байтов в конце структуры
    windowClass.cbClsExtra = NULL;                                    // число освобождаемых байтов при создании экземпляра приложения
    windowClass.hIcon = LoadIcon(NULL, IDI_WINLOGO);                    // дескриптор значка программы (пиктограммы)
    windowClass.hIconSm = LoadIcon(NULL, IDI_WINLOGO);                // дескриптор значка в трее
    windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);                // дескриптор курсора мыши
    windowClass.hbrBackground = (HBRUSH) GetStockObject(WHITE_BRUSH);    // дескриптор кисти для закраски фона окна
    windowClass.hInstance = hInstance;                                    // дескриптор экземпляра приложения
    windowClass.lpszClassName = szClassName;                            // указатель на const-строку, содержащую имя класса
    windowClass.lpszMenuName = NULL;                                    // указатель на const-строку, содержащюю имя меню, применяемого для класса (у нас его нет)

    // проверка регистрации класса WNDCLASSEX:
    if (!RegisterClassEx(&windowClass)) {                        // если отсутствует регистрация класса:
        MessageBox(NULL, "Can't register a class", "Error", MB_OK);
        return NULL;                        // возвращаем NULL, выходим из WinMain()
    }

    // Вызов функции CreateWindow(), создающей окно
    hMainWindow = CreateWindow(
            szClassName,                        // имя нашего класса
            "Complete window procedure",    // имя окна (надпись сверху)
            WS_OVERLAPPEDWINDOW | WS_VSCROLL,    // режимы отображения окна (стили)
            CW_USEDEFAULT,                        // позиция окна по оси х
            NULL,                                // позиция окна по оси y (если в х default, то в Y писать не нужно)
            CW_USEDEFAULT,                        // ширина окна
            NULL,                                // высота окна (если в nWidth default, то в nHeight писать не нужно)
            (HWND) NULL,                            // дескриптор родительского окна
            NULL,                                // дескриптор меню
            HINSTANCE(hInstance),                    // дескриптор экземпляра приложения
            NULL                                // указатель на данные, передаваемые из пользовательской функции WndProc() (ничего не передаём из WindowProcess())
    );

    // Проверка создания окна:
    if (!hMainWindow) {                            // в случае некорректного создания окошка (неверные параметры и тп):
        MessageBox(NULL, "Can't create a window", "Error", MB_OK);
        return NULL;                        // возвращаем NULL, выходим из WinMain()
    }

    // вызов двух функций, взаимодействующих с функцией WindowProcess()

    // отображение окна. Параметры функции: дескриптор окна, стиль отображения окна (При первом запуске окна должен быть равен последнему параметру функции WinMain(), а в последующие разы можно вписывать свои данные)
    ShowWindow(hMainWindow, nCommandShow);
    // обновление окна. Параметр функции: дескриптор окна
    UpdateWindow(hMainWindow);

    // цикл обработки сообщений (извлекает сообщения из очереди, посылаемые функциями, ОС)
    while (GetMessage(&message, NULL, NULL, NULL)) {
        // интерпретация сообщения (используется при обработке нажатых кнопок на клавиатуре)
        TranslateMessage(&message);

        // передача сообщения обратно ОС
        DispatchMessage(&message);
    }

    // возврат кода выхода из приложения
    WPARAM wparam = message.wParam;

    return wparam;
}

// Функция, обрабатывающая процессы, потоки сообщений к/от ОС Windows
LRESULT CALLBACK WindowProcess(HWND hWindow, UINT uMessage, WPARAM wParam, LPARAM lParam) {
    // 1) создание необходимых переменных
    HDC hDC;                                // создание дескриптора ориентации текста в окне
    PAINTSTRUCT paintStructure;             // структура, содержащая информацию о клиентской области (размеры, цвет и т.п.)
    RECT rect;                              // структура, определяющая размер клиентской области (прямоугольная область окна)

    // задание цвета текста
    COLORREF colorText = RGB(255, 0, 0);

    // 2) описание условий, при которых нужно выполнить нужное действие
    switch (uMessage) {
        case WM_PAINT:                            // если нужно нарисовать, то:
            hDC = BeginPaint(hWindow, &paintStructure);        // инициализируем контекст устройства (рисование)
            GetClientRect(hWindow, &rect);            // получаем ширину и высоту области для рисования (выбор области)
            SetTextColor(hDC, colorText);        // устанавливаем цвет контекстного устройства (возвращает цвет текста)
            DrawText(hDC, mainMessage, -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);    // рисование текста
            EndPaint(hWindow, &paintStructure);                // заканчиваем рисовать
            break;
        case WM_DESTROY:                        // если окно закрылось, то:
            // обязательное выполнение условия закрытия окна (отправление WinMain() сообщения WM_QUIT)
            PostQuitMessage(NULL);
            break;
        default:
            // если закрыли окно
            return DefWindowProc(hWindow, uMessage, wParam, lParam);
    }

    return NULL;                            // возврат значения функции
}