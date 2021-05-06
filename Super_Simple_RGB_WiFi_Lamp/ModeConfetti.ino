class ModeConfetti : public ModeBase
{
private:
    // State
    bool confettiActive;
    int confettiPixel;

    // Config
    int confettiSpeed = 100;

public:
    ModeConfetti() {}

    virtual void initialize() {
        confettiActive = true;
        confettiPixel = random(NUM_LEDS);
    }

    virtual void render() {
        EVERY_N_MILLISECONDS(confettiSpeed) {
          if (confettiActive) {
            confettiPixel = random(NUM_LEDS);
            fadeToBlackBy(ledString, NUM_LEDS, 10);
            uint8_t pos = random8(NUM_LEDS);
            ledString[pos] += CHSV(random8(), random8(), random8());
          }
        }
    }

    virtual void applyConfig(JsonVariant& settings) {
        // Are not used
        //settings["Red"] = confettiRed = settings["Red"] | confettiRed;
        //settings["Green"]= confettiGreen = settings["Green"] | confettiGreen;
        //settings["Blue"] = confettiBlue = settings["Blue"] | confettiBlue;
        settings["Speed"] = confettiSpeed = settings["Speed"] | confettiSpeed;
    }
};
