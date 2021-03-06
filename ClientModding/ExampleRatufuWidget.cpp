#include "ExampleRatufuWidget.h"
#include "Utils/Logger.h"

#include "Api/DelphiClasses/TEWCaptionBar.h"
#include "Api/DelphiClasses/TEWCustomFormWidget.h"
#include "Api/DelphiClasses/TEWGraphicButtonWidget.h"
#include "Api/DelphiClasses/TEWLabel.h"

#include "Api/Managers/PacketManager/PacketManager.h"

namespace
{
	std::function<void()> onClick;

	void testFunc()
	{
		onClick();
	}
}

bool ExampleRatufuWidget::Initialize(TLBSWidget* Parent, std::function<void()> OnClick)
{
	if (Parent == nullptr)
		return false;

	onClick = OnClick;

	TEWCustomFormWidget* form = new TEWCustomFormWidget(
		Parent,
		Border(0, 0, 150, 150),
		ImageData(1593835577, 512, 512, new PictureDisplayer({
			PictureView(1, 126, 111, 118)
		})),
		ImagePadding(0, 0, 0, 0, 0, 0)
	);
	Parent->addWidget(form);
	form->setVisible(true);

	TEWLabel* label = new TEWLabel(
		form,
		Border(45, 125, 110, 145),
		TextStyle(3, TextShadowOrientation::ShadowTopLeft, Bgra(0, 255, 255, 127), Bgra(255, 0, 0, 255), TextAlignment::CenteredCentered),
		TextPosition(0, 0, 66, 15, new WString(L"Click me!"), true)
	);
	form->addWidget(label);
	label->setVisible(true);
	TEWCaptionBar* captionBar = new TEWCaptionBar(
		form,
		Border(0, 0, 150, 35), Bgra(255, 255, 0, 127),
		TextStyle(3, TextShadowOrientation::ShadowBottom, Bgra(255, 255, 0, 127), Bgra(255, 0, 0, 255), TextAlignment::CenteredCentered),
		TextPosition(0, 0, 150, 25, new WString(L"Titlebar"), true)
	);
	form->addWidget(captionBar);
	captionBar->setVisible(true);

	TEWGraphicButtonWidget* button = new TEWGraphicButtonWidget(
		form,
		Border(30, 30, 90, 90),
		Bgra(255, 255, 255, 255),
		ImageData(1593835780, 512, 512, new PictureDisplayer({
			PictureView(32, 2, 120, 200),
			PictureView(176, 2, 158, 200),
			PictureView(340, 2, 169, 200)
		})),
		ImagePadding(0, 0, 0, 0, 0, 0),
		Callback(testFunc, 0),
		2, 3
	);
	form->addWidget(button);
	button->setVisible(true);

	return true;
}
