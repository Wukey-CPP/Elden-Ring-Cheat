#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <conio.h> // For _kbhit() and _getch() on Windows

void setColor(int r, int g, int b) {
    std::cout << "\033[38;2;" << r << ";" << g << ";" << b << "m";
}

void resetColor() {
    std::cout << "\033[0m";
}

// Clears the console screen (platform-specific)
void clearScreen() {
    std::cout << "\033[2J\033[H"; // ANSI escape code to clear the screen and move the cursor to the top-left corner
}

void printInstallingMessage() {
    std::string message = "Installing driver...";
    const int totalSteps = 100;

    for (size_t i = 0; i < message.size(); ++i) {
        int r = 0 + (128 * i) / message.size(); // From 0 to 128
        int g = 255; // Keep green constant
        int b = 255 - (255 * i) / message.size(); // From 255 to 128

        setColor(r, g, b);
        std::cout << message[i];
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    resetColor();
    std::cout << std::endl;

    // Progress bar for driver installation
    for (size_t i = 0; i <= totalSteps; ++i) {
        std::cout << "\r" << message;
        std::cout.flush();

        int barWidth = 50;
        float progress = static_cast<float>(i) / totalSteps;
        int pos = barWidth * progress;

        std::cout << " [";
        for (int j = 0; j < barWidth; ++j) {
            if (j < pos) std::cout << "=";
            else std::cout << " ";
        }
        std::cout << "] " << int(progress * 100) << " %";

        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    resetColor();
    std::cout << std::endl;
    std::cout << "Driver installed successfully!" << std::endl;
}

void printUpdateProgressBar(const std::string& message) {
    const int totalSteps = 50;
    int messageSize = message.size();

    // Print the update message with color transition
    for (size_t i = 0; i < message.size(); ++i) {
        int r = 0 + (128 * i) / messageSize;
        int g = 255;
        int b = 255 - (255 * i) / messageSize;

        setColor(r, g, b);
        std::cout << message[i];
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(25));
    }

    std::cout << std::endl;

    // Loading bar for each update message
    for (int i = 0; i <= totalSteps; ++i) {
        std::cout << "\r" << message << " [";
        int barWidth = 30;
        float progress = static_cast<float>(i) / totalSteps;
        int pos = barWidth * progress;

        for (int j = 0; j < barWidth; ++j) {
            if (j < pos) std::cout << "=";
            else std::cout << " ";
        }
        std::cout << "] " << int(progress * 100) << " %";
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    std::cout << std::endl;
    resetColor();
}

void printUpdateSpam() {
    std::string messages[] = {
        "Updating software loader...",
        "Applying patch...",
        "Checking driver integrity...",
        "Verifying driver signature...",
        "Updating security settings...",
        "Updating firmware...",
        "Patching kernel drivers...",
        "Rebooting driver system...",
        "Finalizing update..."
    };

    // Simulate spamming of update messages with progress bars without repeating
    for (const auto& msg : messages) {
        printUpdateProgressBar(msg);
    }
}

void loadingDriverAnimation() {
    std::string spinner = "\\|/-"; // Spinning characters
    std::string message = "Loading driver...";

    // Same color transition as previous messages
    for (size_t i = 0; i < message.size(); ++i) {
        int r = 0 + (128 * i) / message.size();
        int g = 255;
        int b = 255 - (255 * i) / message.size();

        setColor(r, g, b);
        std::cout << message[i];
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    std::cout << " "; // Space after message

    // Animate the spinner
    for (int i = 0; i < 40; ++i) {
        std::cout << "\b" << spinner[i % spinner.size()]; // Rotate spinner
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
    }

    resetColor();
    std::cout << std::endl;
}

void waitRandomTime() {
    srand(static_cast<unsigned int>(time(0))); // Initialize random seed
    int randomTime = rand() % 10 + 1; // Random time between 1 and 10 seconds
    std::this_thread::sleep_for(std::chrono::seconds(randomTime));
}

void promptDriverLoad() {
    std::string driver;
    std::cout << "What driver do you want to load? ";
    std::cin >> driver;

    if (driver == "unrealwindow") {
        std::cout << "Driver loaded successfully!" << std::endl;
    }
    else {
        std::cout << "Invalid driver name!" << std::endl;
    }
}

void displayUpdateInfo() {
    // Get the current date
    std::time_t now = std::time(nullptr);
    std::tm localtm;
    localtime_s(&localtm, &now); // Use localtime_s for safer conversion
    char dateStr[100];
    std::strftime(dateStr, sizeof(dateStr), "%Y-%m-%d", &localtm);

    // Displaying the required information
    clearScreen();
    std::cout << "[+] Elden Ring Internal (UPDATE DAY " << dateStr << " !!!!!)\n";
    std::cout << "[+] Build Date: " << dateStr << "\n";
    std::cout << "[+] Build Version: alpha-0.7.3\n";
    std::cout << "[+] Made By Wukey and 17 more people\n";
    std::cout << "[!] no longer preview\n";
    std::cout << "[!] inject whenever tf you want\n";
    std::cout << "[+] FMV'S SKIPPED\n";
    std::cout << "[+] FPS UNCAPPED\n\n";

    // Displaying change log with the same text color
    std::string changeLog[] = {
        "[+] WorldChar::MAN - Improved character animations for smoother movement.",
        "[+] GameEngine::StartUp - Optimized initialization process to reduce load times.",
        "[+] RenderSystem::ApplyShadows - Enhanced shadow rendering for more realistic lighting effects.",
        "[+] Network::SendPacketV2 - Replaced deprecated packet sending method with improved version.",
        "[+] Physics::ApplyForce - Increased efficiency in handling interactions between larger objects.",
        "[+] UI::DisplayHealthBar - Updated health bar transitions for better user experience.",
        "[+] AudioEngine::PlayBackgroundMusic - Integrated dynamic music playback based on game events.",
        "[+] WorldObject::Destroy - Fixed memory leak issue when destroying objects in-game.",
        "[+] InputManager::HandleKeyPress - Added support for customizable key bindings.",
        "[+] Inventory::AddItem - Updated item addition to support new item categories and types.",
        "[+] AI::Pathfinding::CalculateRoute - Improved navigation algorithm for more accurate AI movement.",
        "[+] Player::Jump - Adjusted jump mechanics to factor in environmental conditions.",
        "[+] GameState::SaveGame - Resolved crash issues occurring during game save operations.",
        "[+] WeaponSystem::Reload - Reworked reload animations for increased responsiveness.",
        "[+] Shader::CompileVulkanSupport - Added support for Vulkan shaders, replacing legacy compilation methods.",
        "[+] Camera::AdjustZoom - Enhanced zoom functionality for better focus on distant objects.",
        "[+] Achievements::Unlock - Fixed bugs preventing achievement unlocking under certain conditions.",
        "[+] Menu::Settings - Improved layout and accessibility of the settings menu.",
        "[+] Debug::LogErrors - Enhanced error logging for better tracking of runtime issues.",
        "[+] Physics::CollisionDetection - Updated collision detection algorithm for greater accuracy.",
        "[+] Animation::BlendTree - Added support for more complex animation blending."
    };

    // Set color for change logs
    for (const auto& log : changeLog) {
        setColor(0, 255, 255); // Cyan color for logs
        std::cout << log << std::endl;
    }
    resetColor();
}

int main() {
    loadingDriverAnimation();
    waitRandomTime();
    printInstallingMessage();
    promptDriverLoad();
    displayUpdateInfo();
    printUpdateSpam();
    return 0;
}
