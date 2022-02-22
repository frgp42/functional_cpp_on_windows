#pragma once

#include "MainWindow.g.h"

#include "counter.hpp"

#include <lager/event_loop/manual.hpp>
#include <lager/store.hpp>

namespace winrt::winui_counter::implementation
{

struct MainWindow : MainWindowT<MainWindow>
{
	MainWindow();

	void decrementButton_Click(const winrt::Windows::Foundation::IInspectable& sender,
		                       const winrt::Microsoft::UI::Xaml::RoutedEventArgs& e);
	void incrementButton_Click(const winrt::Windows::Foundation::IInspectable& sender,
		                       const winrt::Microsoft::UI::Xaml::RoutedEventArgs& e);
	winrt::event_token PropertyChanged(const winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventHandler& handler);
	void PropertyChanged(const winrt::event_token& token) noexcept;
	int32_t Value();

private:
	lager::store <counter::action, counter::model> m_store;
	winrt::event<Microsoft::UI::Xaml::Data::PropertyChangedEventHandler> m_propertyChanged;
};

} // namespace winrt::winui_counter::implementation

namespace winrt::winui_counter::factory_implementation
{

struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
{
};

} // namespace winrt::winui_counter::factory_implementation
