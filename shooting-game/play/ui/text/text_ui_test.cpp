#include "shooting-game/play/ui/text/text_ui.h"

#include <gtest/gtest.h>

TEST(TextTest, BasicTest) {
  sg::play::ui::TextUi textUi;

  textUi.UpdateText("SAMPLE TEXT");
  EXPECT_EQ(textUi.GetText(), "SAMPLE TEXT");

  textUi.UpdateText("SAMPLE TEXT2");
  EXPECT_EQ(textUi.GetText(), "SAMPLE TEXT2");
}
