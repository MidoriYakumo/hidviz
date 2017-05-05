//
// hidviz - Tool for in-depth analysis of USB HID devices communication
// Copyright (C) 2017 Ondrej Budai <ondrej@budai.cz>
//
// This file is part of hidviz.
//
// hidviz is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// hidviz is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with hidviz.  If not, see <http://www.gnu.org/licenses/>.
//

#ifndef HIDVIZ_CONTROL_HH
#define HIDVIZ_CONTROL_HH

#include "ItemWidget.hh"

namespace Ui {
    class ControlSubWidget;
}

namespace libhidx {
namespace hid {
    class Control;
    class Usage;
}
}

namespace hidviz {
namespace hid {
    class UsageWidget;
    class ControlWidget : public ItemWidget {
    Q_OBJECT
    public:
        ControlWidget(libhidx::hid::Control*, QWidget* parent = nullptr);
        void updateData();
    private:
        libhidx::hid::Control* m_control;
        QList<UsageWidget*> m_usageWidgets;
        Ui::ControlSubWidget* ui;

        void initGui();
        void initUsages();
        void initInfoTable();

    signals:
        void dataUpdated();


    };
}
}


#endif //HIDVIZ_CONTROL_HH
