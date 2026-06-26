// Login Form
const loginForm = document.getElementById('loginForm');
if (loginForm) {
    loginForm.addEventListener('submit', function(e) {
        e.preventDefault();
        const email = document.getElementById('email').value;
        const password = document.getElementById('password').value;
        
        // Basic validation
        if (email && password) {
            // Store in localStorage for demo
            localStorage.setItem('userEmail', email);
            localStorage.setItem('loggedIn', 'true');
            alert('Login successful! Redirecting...');
            window.location.href = 'dashboard.html';
        } else {
            alert('Please fill all fields');
        }
    });
}

// Register Form
const registerForm = document.getElementById('registerForm');
if (registerForm) {
    registerForm.addEventListener('submit', function(e) {
        e.preventDefault();
        const name = document.getElementById('name').value;
        const email = document.getElementById('email').value;
        const phone = document.getElementById('phone').value;
        const password = document.getElementById('password').value;
        const confirmPassword = document.getElementById('confirm-password').value;
        
        // Validation
        if (!name || !email || !phone || !password || !confirmPassword) {
            alert('Please fill all fields');
            return;
        }
        
        if (password !== confirmPassword) {
            alert('Passwords do not match');
            return;
        }
        
        if (password.length < 6) {
            alert('Password must be at least 6 characters');
            return;
        }
        
        // Store user data
        const userData = {
            name: name,
            email: email,
            phone: phone,
            registeredDate: new Date().toISOString()
        };
        
        localStorage.setItem('userData_' + email, JSON.stringify(userData));
        alert('Registration successful! Please login.');
        window.location.href = 'login.html';
    });
}

// Check authentication
function checkAuth() {
    const loggedIn = localStorage.getItem('loggedIn');
    if (!loggedIn && window.location.pathname.includes('dashboard')) {
        window.location.href = 'login.html';
    }
}

checkAuth();