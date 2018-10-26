#include <gmock\gmock.h>
#include <Windows.h>
#include "RunCode.h"
#include "TestCode.h"


static char* removeStr[] = {
	"this",
	"nope",
	"string",
	"not",
};

static char* removed[] = {
	" is a string",
	"this is also a , unlike the first string",
	"another one,  a great one, and not really like the last two.",
};

static char* stringlist[] = {
	"this is a string",
	"this is also a string, unlike the first string",
	"another one, not a great one, and not really like the last two.",
	"a third string!",
	NULL,
};

TEST(TestSetOne, DeleteWordTest_remove_a_word)
{
	char buf[MAX_PATH + 1] = { 0 };
	char buf1[MAX_PATH + 1] = { 0 };
	_snprintf(buf, MAX_PATH, "%s", stringlist[0]);

	ASSERT_EQ(ERROR_SUCCESS, deleteWord(buf, removeStr[0]));
	ASSERT_EQ(ERROR_SUCCESS, strcmp(buf, removed[0]));
}


TEST(TestSetOne, DeleteWordTest_bad_input)
{
	ASSERT_EQ(ERROR_INVALID_PARAMETER, deleteWord(stringlist[0], NULL));
	ASSERT_EQ(ERROR_INVALID_PARAMETER, deleteWord(NULL, removeStr[0]));
}

TEST(TestSetOne, DeleteWordTest_item_not_found)
{
	char buf[MAX_PATH + 1] = { 0 };
	_snprintf(buf, MAX_PATH, "%s", stringlist[1]);
	ASSERT_EQ(ERROR_NOT_FOUND, deleteWord(buf, removeStr[1]));
}
