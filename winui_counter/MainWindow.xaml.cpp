#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

namespace winrt::winui_counter::implementation
{

MainWindow::MainWindow() :
	m_store(lager::make_store<counter::action>(counter::model{},
		    lager::with_manual_event_loop{}))
{
	InitializeComponent();
	// Unable to set title in XAML
	// https://github.com/microsoft/microsoft-ui-xaml/issues/3689
	Title(L"WinUI Lager Counter Example");
	lager::watch(m_store, [&](counter::model /*m*/)
		{ m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"Value" }); });
}

void MainWindow::incrementButton_Click(const winrt::Windows::Foundation::IInspectable& sender,
	const winrt::Microsoft::UI::Xaml::RoutedEventArgs& e)
{
	m_store.dispatch(counter::increment_action{});
}

void MainWindow::decrementButton_Click(const winrt::Windows::Foundation::IInspectable& sender,
	const winrt::Microsoft::UI::Xaml::RoutedEventArgs& e)
{
	m_store.dispatch(counter::decrement_action{});
}

winrt::event_token MainWindow::PropertyChanged(const winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventHandler& handler)
{
	return m_propertyChanged.add(handler);
}

void MainWindow::PropertyChanged(const winrt::event_token& token) noexcept
{
	m_propertyChanged.remove(token);
}

int32_t MainWindow::Value()
{
	return m_store.get().value;
}

}
