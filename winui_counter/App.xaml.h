#pragma once

#include "App.xaml.g.h"

namespace winrt::winui_counter::implementation
{

    struct App : AppT<App>
    {
        App();

        void OnLaunched(const Microsoft::UI::Xaml::LaunchActivatedEventArgs&);

    private:
        winrt::Microsoft::UI::Xaml::Window window{ nullptr };
    };

} // namespace winrt::winui_counter::implementation
