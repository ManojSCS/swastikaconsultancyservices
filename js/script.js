// Shopping Cart
let cart = [];

function addToCart(packageName, price) {
    const item = {
        id: Date.now(),
        name: packageName,
        price: price,
        quantity: 1
    };
    cart.push(item);
    updateCartCount();
    alert(`${packageName} Package added to cart!`);
}

function updateCartCount() {
    document.getElementById('cartCount').textContent = cart.length;
}

function openCart() {
    alert(`Cart Items: ${cart.length}\nTotal: ₹${getTotalPrice()}\n\nFeature: Cart page coming soon!`);
}

function getTotalPrice() {
    return cart.reduce((total, item) => total + (item.price * item.quantity), 0);
}

function scrollTo(sectionId) {
    const element = document.getElementById(sectionId);
    if (element) {
        element.scrollIntoView({ behavior: 'smooth' });
    }
}

// Initialize
document.addEventListener('DOMContentLoaded', function() {
    console.log('Swastika Consultancy Services - Website Loaded');
    updateCartCount();
});