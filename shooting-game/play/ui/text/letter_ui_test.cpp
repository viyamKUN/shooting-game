#include "shooting-game/play/ui/text/letter_ui.h"

#include <gtest/gtest.h>

TEST(LetterTest, BasicTest) {
  sg::play::ui::LetterUi letterUi;

  EXPECT_EQ(letterUi.TryUpdateLetter('B'), true);
  EXPECT_EQ(letterUi.TryUpdateLetter('D'), true);
  EXPECT_EQ(letterUi.TryUpdateLetter('Z'), true);

  EXPECT_EQ(letterUi.TryUpdateLetter('a'), false);
  EXPECT_EQ(letterUi.TryUpdateLetter(1), false);
}
